#===============================================================================
# Variables ====================================================================
#===============================================================================
NAME		:=	libftprintf.a

# Directories ------------------------------------------------------------------
LIBFT_DIR	:=	lib/libft/
SRC_DIR		:=	src/
OBJ_DIR		:=	build/

# Files ------------------------------------------------------------------------
FILES		:=	ft_printf.c ft_printf_utils_alpha.c ft_printf_utils_numbers.c
LIBFT_FILES	:=	ft_putnbr_fd.c ft_putchar_fd.c ft_putnbr_fd.c\
				ft_putstr_fd.c ft_strlen.c
OBJ			:=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
LIBFT_OBJ	:=	$(addprefix $(OBJ_DIR), $(LIBFT_FILES:.c=.o))

# Compiler ---------------------------------------------------------------------
CC			:=	cc
DEBUG		:=	no
ifeq ($(DEBUG), yes)
FLAG		:=	-g -W
else
FLAG		:=	-Wall -Wextra -Werror
endif

#===============================================================================
# Rules ========================================================================
#===============================================================================
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c make_build_dir
	$(CC) $(FLAG) -c $< -o $@

make_build_dir:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(LIBFT_DIR)$(SRC_DIR)%.c
	$(CC) $(FLAG) -c $< -o $@

# Clean up ---------------------------------------------------------------------
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: all make_build_dir clean fclean re
