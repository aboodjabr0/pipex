# 🚀 Pipex

A 42 School project that recreates the behavior of shell pipe operations in C. This program mimics the way shell commands are piped together, allowing you to chain commands just like in bash.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Mandatory Part](#mandatory-part)
  - [Bonus Part](#bonus-part)
- [Examples](#examples)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Requirements](#requirements)

## 🎯 About

Pipex is a program that handles pipes (`|`) between two commands, redirecting input and output between files. It demonstrates understanding of:

- **Process management** (fork, execve, wait)
- **File descriptors** manipulation
- **Pipes** and inter-process communication
- **System calls** in Unix/Linux

The program behavior is equivalent to the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

## ✨ Features

### Mandatory
- Execute two commands with a pipe between them
- Read input from a file
- Write output to another file
- Proper error handling
- No memory leaks

### Bonus
- Support for **multiple pipes** (unlimited number of commands)
- **Here document** (`<<`) implementation
- Append mode support (`>>`)

## 🔧 Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/aboodjabr0/pipex.git
cd pipex
make
```

For the bonus version:
```bash
make bonus
```

To clean object files:
```bash
make clean
```

To remove all compiled files:
```bash
make fclean
```

To recompile:
```bash
make re
```

## 💻 Usage

### Mandatory Part

```bash
./pipex file1 cmd1 cmd2 file2
```

This executes the equivalent of:
```bash
< file1 cmd1 | cmd2 > file2
```

**Parameters:**
- `file1`: Input file
- `cmd1`: First command with its parameters
- `cmd2`: Second command with its parameters
- `file2`: Output file

### Bonus Part

#### Multiple Pipes
```bash
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
```

This executes the equivalent of:
```bash
< file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```

#### Here Document
```bash
./pipex_bonus here_doc LIMITER cmd1 cmd2 file
```

This executes the equivalent of:
```bash
cmd1 << LIMITER | cmd2 >> file
```

**Parameters:**
- `here_doc`: Special keyword to activate here_doc mode
- `LIMITER`: Delimiter to stop reading from stdin
- `cmd1, cmd2`: Commands to execute
- `file`: Output file (opened in append mode)

## 📝 Examples

### Example 1: Basic Usage
```bash
./pipex infile "ls -l" "wc -l" outfile
```
Equivalent to:
```bash
< infile ls -l | wc -l > outfile
```

### Example 2: Text Processing
```bash
./pipex input.txt "grep hello" "wc -w" output.txt
```
Equivalent to:
```bash
< input.txt grep hello | wc -w > output.txt
```

### Example 3: Multiple Pipes (Bonus)
```bash
./pipex_bonus infile "cat" "grep a" "sort" "uniq" outfile
```
Equivalent to:
```bash
< infile cat | grep a | sort | uniq > outfile
```

### Example 4: Here Document (Bonus)
```bash
./pipex_bonus here_doc EOF "cat" "wc -l" outfile
```
Then type some lines and end with `EOF`. Equivalent to:
```bash
cat << EOF | wc -l >> outfile
```

## 🔍 How It Works

### Process Flow

1. **Fork Process**: Creates child processes for each command
2. **Create Pipe**: Establishes communication channel between processes
3. **File Descriptors**: Redirects stdin/stdout using `dup2()`
4. **Execute Command**: Uses `execve()` to run the command
5. **Wait**: Parent process waits for children to complete

### Key System Calls

- `fork()`: Create a new process
- `pipe()`: Create a pipe for inter-process communication
- `dup2()`: Duplicate file descriptors for redirection
- `execve()`: Execute a command
- `waitpid()`: Wait for child process to finish
- `open()`: Open files for reading/writing
- `close()`: Close file descriptors

### File Descriptor Management

```
Input File → STDIN (fd 0) → CMD1 → PIPE → CMD2 → STDOUT (fd 1) → Output File
```

## 📂 Project Structure

```
pipex/
├── pipex.c                 # Main program (mandatory)
├── pipex.h                 # Header file
├── pipex_utils.c          # Utility functions
├── Makefile               # Build configuration
├── bonus/
│   ├── pipex_bonus.c      # Bonus implementation
│   ├── pipex_bonus.h      # Bonus header
│   ├── pipex_utils_bonus.c
│   ├── helpers.c          # Helper functions
│   └── get_next_line.c    # GNL for here_doc
└── libft/                 # Custom C library
    ├── *.c                # Libft functions
    ├── libft.h
    └── ft_printf/         # Printf implementation
```

## 📋 Requirements

- **OS**: Linux/Unix
- **Compiler**: gcc or clang
- **Compilation flags**: `-Wall -Wextra -Werror`
- **Standard**: C99 or later

## 🎓 Learning Outcomes

This project teaches:

- ✅ Understanding of Unix process creation and management
- ✅ File descriptor manipulation and redirection
- ✅ Inter-process communication using pipes
- ✅ System calls and their error handling
- ✅ Memory management and leak prevention
- ✅ Working with environment variables
- ✅ Path resolution for executables

## 🐛 Error Handling

The program handles various error cases:

- Invalid number of arguments
- File opening failures
- Command not found
- Permission denied
- Pipe creation failures
- Fork failures
- Memory allocation failures

## 📜 License

This project is part of the 42 School curriculum.

## 👤 Author

**Abduallah** **Sauafth** - [GitHub](https://github.com/aboodjabr0)

---

*Made with ❤️ at 42 School*
