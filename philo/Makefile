# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/08/23 17:06:14 by Clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo

SRC_EXTENSION		:= \
	.c

SRC_NAME			:= \
	main

S_DIR		 		:= \
	./

O_DIR				:= \
	./

I					:= \
	-I ./

O					= \
	$(addprefix $(O_DIR), $(addsuffix .o, $(SRC_NAME)))

C					:= gcc
CFLAGS				:= -Wall -Wextra -Werror

R					:= rm -f

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION)
	$C $(CFLAGS) $I -c $< -o $@

all:				$(NAME)

$(NAME):			$O
	$C $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re
