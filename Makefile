# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 15:51:51 by dabel-co          #+#    #+#              #
#    Updated: 2021/11/22 15:19:19 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -g3 -fsanitize=address #-Wall -Werror -Wextra
CC = cc
FILES =	push_swap \
		operations \
		short_sorting \
		big_sorting \

C = $(addprefix ./src/ft_, $(addsuffix .c, $(FILES)))
#REMOVE FLAG
all: $(NAME)

$(NAME) :	check_libft
	@$(CC) $(FLAGS) $(LINK) $(C) $(GNL) ./Libft/libft.a -o $(NAME)
check_libft :
	@if test -d Libft; then ( cd Libft ; git pull ) ; else git clone https://github.com/dabel-co/Libft.git; fi
	@make extra -C ./Libft
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re check_libft
