#===============================================================================
# Variables ====================================================================
#===============================================================================
NAME		:=	libftprintf.a

# Directories ------------------------------------------------------------------
SRC_DIR			:=	src/
OBJ_DIR			:=	build/
LIBFT_DIR		:=	lib/libft/

# Files ------------------------------------------------------------------------
FILES		:=	ft_printf.c ft_printf_utils_alpha.c ft_printf_utils_numbers.c
BONUS		:=	ft_printf_bonus.c
# ft_printf_utils_alpha_bonus.c ft_printf_utils_numbers_bonus.c
OBJ			:=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
OBJ_B		:=	$(addprefix $(OBJ_DIR), $(BONUS:.c=.o))
LIBFT_A		:=	libft.a

# Compiler ---------------------------------------------------------------------
CC				:=	cc
DEBUG			:=	no
ifeq ($(DEBUG), yes)
FLAG		:=	-g -W
else
FLAG		:=	-Wall -Wextra -Werror
endif

#===============================================================================
# Rules ========================================================================
#===============================================================================
all: $(NAME)

#bonus: $(OBJ_B) libft_bonus
#	ar rcs $(NAME) $(OBJ_B)

$(NAME): $(OBJ) $(LIBFT_DIR)$(LIBFT_A)
	ar rcs $(NAME) $(OBJ) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c make_build_dir
	$(CC) $(FLAG) -c $< -o $@

make_build_dir:
	mkdir -p $(OBJ_DIR)

libft_bonus:
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT_A) $(NAME)

$(LIBFT_DIR)$(LIBFT_A):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT_A) $(NAME)

# Clean up ---------------------------------------------------------------------
clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: all make_build_dir clean fclean re
