#!/usr/bin/env bash
# run_pipex_tests.sh
# Automated tests for pipex. Compares ./pipex behavior vs shell pipeline.
set -u
# Temporary working dir
TMPDIR="$(mktemp -d)"
PIPEX="./pipex"   # path to your executable
TOTAL=0
PASSED=0

cleanup() {
  rm -rf "$TMPDIR"
}
trap cleanup EXIT

# Helper: run a single test case
# Arguments:
#  $1 - test name (string)
#  $2 - infile content (string; can be multiline)
#  $3 - cmd1 (string, quoted exactly as you'd pass to pipex)
#  $4 - cmd2 (string)
#  $5 - optional: env modifier prefix for shell and pipex (e.g. "env -u PATH") - pass empty string if none
#  $6 - optional: a setup function body (bash code) executed before running the test (useful for chmod)
run_case() {
  local name="$1"; shift
  local infile_content="$1"; shift
  local cmd1="$1"; shift
  local cmd2="$1"; shift
  local envprefix="${1:-}"; shift || true
  local setup_code="${1:-}"; shift || true

  TOTAL=$((TOTAL+1))
  local IN="$TMPDIR/infile"
  local OUT_SHELL="$TMPDIR/out_shell"
  local OUT_PX="$TMPDIR/out_pipex"
  rm -f "$IN" "$OUT_SHELL" "$OUT_PX"

  # create infile (if infile_content is non-empty)
  if [ -n "$infile_content" ]; then
    printf "%s" "$infile_content" > "$IN"
  fi

  # run setup code if provided (for permission changes etc)
  if [ -n "$setup_code" ]; then
    ( eval "$setup_code" )
  fi

  # Run the shell pipeline. Use bash -c with set -o pipefail so the pipeline exit code reflects failures.
  if [ -n "$envprefix" ]; then
    bash -c "set -o pipefail; $envprefix bash -c 'eval \"< \\\"$IN\\\" $cmd1 | $cmd2 > \\\"$OUT_SHELL\\\"\"' " 2>/dev/null
    RC_SHELL=$?
  else
    bash -c "set -o pipefail; eval \"< \\\"$IN\\\" $cmd1 | $cmd2 > \\\"$OUT_SHELL\\\"\"" 2>/dev/null
    RC_SHELL=$?
  fi

  # Run your pipex
  if [ -n "$envprefix" ]; then
    eval "$envprefix \"$PIPEX\" \"$IN\" \"$cmd1\" \"$cmd2\" \"$OUT_PX\""
    RC_PX=$?
  else
    "$PIPEX" "$IN" "$cmd1" "$cmd2" "$OUT_PX"
    RC_PX=$?
  fi

  # Ensure files exist for comparison (touch empty if missing)
  [ -f "$OUT_SHELL" ] || : > "$OUT_SHELL"
  [ -f "$OUT_PX" ] || : > "$OUT_PX"

  # Compare outputs and exit codes
  if diff -u "$OUT_SHELL" "$OUT_PX" >/dev/null 2>&1 && [ "$RC_SHELL" -eq "$RC_PX" ]; then
    echo -e "✅ PASS: $name"
    PASSED=$((PASSED+1))
  else
    echo -e "❌ FAIL: $name"
    echo "  -- shell exit: $RC_SHELL    pipex exit: $RC_PX"
    echo "  -- shell output (>>>):"
    sed 's/^/    /' "$OUT_SHELL" | sed -n '1,20p'
    echo "  -- pipex output (>>>):"
    sed 's/^/    /' "$OUT_PX" | sed -n '1,20p'
    echo "  -- full diff (shell vs pipex):"
    diff -u "$OUT_SHELL" "$OUT_PX" || true
    echo "  (end fail details)"
  fi
  echo
}

# Test 1: Basic working case: cat | wc -l
run_case "Basic: cat | wc -l" $'a
b
a
' "cat" "wc -l"

# Test 2: Commands with arguments: grep ^a | wc -l
run_case "grep ^a | wc -l" $'a
b
ax
' "grep '^a'" "wc -l"

# Test 3: Absolute path commands: /bin/ls -1
mkdir -p "$TMPDIR/lsdir"
touch "$TMPDIR/lsdir/file1" "$TMPDIR/lsdir/file2" "$TMPDIR/lsdir/file3"
run_case "Absolute path: /bin/ls -1" "" "/bin/ls -1 $TMPDIR/lsdir" "wc -l"

# Test 4: Missing infile
run_case "Missing infile" "" "cat" "wc -l" "" "rm -f \"$TMPDIR/infile\""

# Test 5a: Permission denied on infile (unreadable infile)
run_case "Permission denied: infile unreadable" $'a
b
' "cat" "wc -l" "" "printf '%s' 'secret' > \"$TMPDIR/infile\" && chmod 000 \"$TMPDIR/infile\""

# Test 5b: Permission denied on outfile (unwritable)
run_case "Permission denied: outfile unwritable" $'a
b
' "cat" "wc -l" "" "touch \"$TMPDIR/out_shell\" && chmod 444 \"$TMPDIR/out_shell\" && touch \"$TMPDIR/out_pipex\" && chmod 444 \"$TMPDIR/out_pipex\""

# Test 6: Command not found
run_case "Command not found" $'a
b
' "no_such_cmd" "wc -l"

# Test 7: Command not executable (absolute path to a non-executable script)
cat > "$TMPDIR/not_exec.sh" <<'EOF'
#!/bin/sh
echo hello
EOF
chmod 644 "$TMPDIR/not_exec.sh"
run_case "Command not executable (permission)" "" "$TMPDIR/not_exec.sh" "wc -l"

# Test 8: Commands that output nothing (grep that matches nothing)
run_case "Commands that output nothing" $'one
two
three
' "grep 'nomatchpattern'" "wc -l"

# Test 9: Empty command string
run_case "Empty command string" $'a
' "" "wc -l"

# Test 10: PATH unset environment
run_case "PATH unset" $'a
b
' "grep a" "wc -l" "env -u PATH"

# Summary
echo "===== SUMMARY ====="
echo "Total tests: $TOTAL"
echo "Passed:      $PASSED"
echo "Failed:      $((TOTAL - PASSED))"
if [ "$PASSED" -eq "$TOTAL" ]; then
  echo "ALL TESTS PASSED ✅"
else
  echo "Some tests failed ❌"
fi
