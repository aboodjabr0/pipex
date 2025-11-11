NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = pipex.c\
		pipex_utils.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = bonus/helpers.c \
			bonus/pipex_utils_bonus.c \
			bonus/pipex_bonus.c \
			bonus/get_next_line.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GREEN = \033[0;32m
RED_BOLD = \033[1;31m
RESET = \033[0m

all : $(NAME)
$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Getting pipex ready ⏳$(RESET)"
	@echo "$(GREEN)____________________$(RESET)"
	@echo "$(GREEN)    pipex is ready ✅$(RESET)"
	@echo "$(GREEN)____________________$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)
clean : 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(RED_BOLD)Object files cleaned 🧹$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(RED_BOLD)Pipex executables removed 🧹$(RESET)"

re : fclean all

.PHONY :
	all bonus clean fclean re

bonus : $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)_bonus
	@echo "$(GREEN)Getting bonus pipex ready ⏳$(RESET)"
	@echo "$(GREEN)____________________$(RESET)"
	@echo "$(GREEN)    pipex_bonus is ready ✅$(RESET)"
	@echo "$(GREEN)____________________$(RESET)"
