# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 14:09:03 by clkuznie          #+#    #+#              #
#    Updated: 2021/10/14 19:00:27 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo

SRC_EXTENSION		:= \
	.c

SRC_NAME			:= \
	initialization \
	main \
	philo_birth \
	philo_check \
	philo_in \
	philo_lifeline \
	philo_out \
	utils \
	thread_behaviour \
	time_functions

H_EXTENTION			:= \
	.h

H_NAME				:= \
	$(NAME)

S_DIR		 		:= \
	src/

O_DIR				:= \
	obj/

I					:= \
	-I ./

O					= \
	$(addprefix $(O_DIR), $(addsuffix .o, $(SRC_NAME)))

C					:= gcc
CFLAGS				:= -Wall -Wextra -Werror $I

L					:= -pthread

R					:= rm -f

$(O_DIR)%.o:		$(S_DIR)%.c $(H_NAME).h
	$C $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$O
	$C $L $^ -o $@

debug:				$O
	$C -g $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re debug
