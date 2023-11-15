# NAMES
NAME = push_swap
NAME_BONUS = checker

# LIBFT
LIBFT = libft/libft.a

# SOURCE FILES
SRC_DIR			=	src/
SRC_BONUS_DIR	=	checker/
SRC_FILES		= 	main.c \
					parsing.c \
					list_utils_1.c \
					list_utils_2.c \
					moves.c \
					choose_move.c \
					sort_three.c \
					big_size_algo.c \
					push_till_three.c \
					utils_1.c \
					utils_2.c
# big_size_algo.c
BONUS_FILES		=	checker.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_BONUS		=	$(addprefix $(SRC_BONUS_DIR), $(BONUS_FILES))

# OBJECT FILES
OBJ_FILES 		= $(SRC:.c=.o)
OBJ_BONUS_FILES = $(SRC_BONUS:.c=.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
INCLUDE = -I includes
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	@make -sC libft
	@echo "$(PINK)Compiling the PUSH_SWAP program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) $(INCLUDE) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

bonus:	$(NAME) $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS_FILES)
	@make -sC libft
	@echo "$(PINK)Compiling the CHECKER program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_BONUS_FILES) $(INCLUDE) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	$(RM) $(OBJ_FILES)
	$(RM) $(OBJ_BONUS_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	@echo "$(PINK)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all bonus clean fclean re