# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:40:53 by ylabrahm          #+#    #+#              #
#    Updated: 2023/05/02 16:48:48 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = init_dead_mutex.c launch_threads_utils.c ft_check_args.c launch_threads.c philo.c timing.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Werror -Wall

CC = cc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all