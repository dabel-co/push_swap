# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 15:51:51 by dabel-co          #+#    #+#              #
#    Updated: 2021/10/27 15:26:18 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = #-g3 -fsanitize=address #-Wall -Werror -Wextra
CC = cc
FILES =	push_swap \
		utils \

C = $(addprefix ./src/ft_, $(addsuffix .c, $(FILES)))
#REMOVE FLAG
all: $(NAME)

$(NAME) :	check_libft
	@$(CC) $(FLAGS) $(LINK) $(C) $(GNL) ./src/libft/libft.a -o $(NAME)
check_libft :
	@make bonus -C ./src/libft
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./src/libft
re: clean all

.PHONY : all clean fclean re check_libft
