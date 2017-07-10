#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 16:19:42 by emasiuk           #+#    #+#              #
#    Updated: 2016/11/30 16:19:43 by emasiuk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I $(IDIR)

SRCS = ./tools.c \
		./costyli.c \
		./create_map.c \
		./file_descr.c \
		./find_coords.c \
		./main.c \
		./solve.c \
		./validation.c \
		./show.c \

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
