# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 16:35:26 by akaseris          #+#    #+#              #
#    Updated: 2018/03/30 18:11:04 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

SRC = src/
INC = includes/
OBJ = objects/
LIB = libft/libft.a

FLAGS = -Wall -Werror -Wextra

FT = ft_checker ft_push_swap
FT_OTHER = ft_validinp ft_rules ft_moves ft_sort

FT_O = $(patsubst %,%.o,$(FT) $(FT_OTHER))
FT_O_OBJ = $(patsubst %,$(OBJ)%.o,$(FT) $(FT_OTHER))
FT_O_OBJ_1 = $(OBJ)ft_checker.o
FT_O_OBJ_2 = $(OBJ)ft_push_swap.o
FT_O_OBJ_OTHER = $(patsubst %,$(OBJ)%.o,$(FT_OTHER))
FT_C = $(patsubst %,$(SRC)%.c,$(FT) $(FT_OTHER))


.PHONY : all clean fclean re

all: $(NAME1) $(NAME2)
	@echo '\033[1;32m'***Push_Swap Project Compiled***'\033[0m'

$(LIB):
	@make -C libft/ all

$(FT_O_OBJ): $(LIB)
	@echo '\033[0;34m'***Compiling Push_Swap***'\033[0m'
	@gcc -I $(INC) $(FLAGS) -c $(FT_C)
	@mkdir $(OBJ) 2> /dev/null || true
	@mv $(FT_O) $(OBJ)

$(NAME1): $(FT_O_OBJ)
	@gcc -o $(NAME1) $(FT_O_OBJ_OTHER) $(FT_O_OBJ_1) libft/libft.a
	@echo '\033[0;32m'***Checker Compiled***'\033[0m'

$(NAME2): $(FT_O_OBJ)
	@gcc -o $(NAME2) $(FT_O_OBJ_OTHER) $(FT_O_OBJ_2) libft/libft.a
	@echo '\033[0;32m'***push_swap Compiled***'\033[0m'

clean:
	@/bin/rm -rf $(OBJ)
	@echo '\033[0;31m'***Deleted Push_Swap Objects***'\033[0m'
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@echo '\033[0;31m'***Deleted Push_Swap Objects and Library***'\033[0m'
	@make -C libft/ fclean

re: fclean all
