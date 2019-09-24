# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 16:12:18 by ghtouman          #+#    #+#              #
#    Updated: 2019/08/09 16:07:37 by tigre            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Werror -Wextra
IDIR = ./includes/
NAME = lem-in
SRC_PATH = ./srcs/
LIB_PATH = ./libft/
LIB = libft/libft.a

FILES =	lem_in.c			\
		bfs.c				\
		bfs_utils.c			\
		clean.c				\
		clean2.c			\
		fill_buf.c			\
		follow_the_rabbit.c	\
		get_ant.c			\
		get_room.c			\
		get_way.c			\
		get_flux.c			\
		potentiel_result.c	\
		print_sol.c			\
		utils.c				\
		utils2.c			\
		lem_in_options.c	\
		lem_in_options2.c

SRCS_FILES = $(addprefix srcs/, $(FILES))
OBJ = $(SRCS_FILES:.c=.o)

all:$(NAME)
$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LIB) -I $(LIB_PATH) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@ -I$(IDIR) -g

$(OBJ) : $(IDIR)lem_in.h

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIB_PATH)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(LIB)

re: fclean all

libft/libft.a: FORCE
	$(MAKE) -C libft -j

FORCE:

.PHONY: all clean fclean re
