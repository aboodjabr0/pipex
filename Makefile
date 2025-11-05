NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

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
	@cd libft && make --no-print-directory

clean : 
	@rm -f $(OBJS)
	@echo "$(RED_BOLD)Object files cleaned 🧹$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED_BOLD)Pipex executable removed 🧹$(RESET)"

re : fclean all

.PHONY :
	all clean fclean re
