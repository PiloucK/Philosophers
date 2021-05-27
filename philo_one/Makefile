# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 16:10:32 by clkuznie          #+#    #+#              #
#    Updated: 2021/05/27 16:13:47 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo_one

SRC_EXTENSION		:= \
	.c

SRC_NAME			:= \
	$(NAME) \
	main

H					:= \
	$(NAME).H

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

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION) $H
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
