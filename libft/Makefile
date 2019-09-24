# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 12:02:58 by ghtouman          #+#    #+#              #
#    Updated: 2019/08/09 16:13:21 by tigre            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAG = -Wall -Werror -Wextra
NAME = libft.a

SRC = ft_atoi.c					\
		ft_bzero.c				\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isprint.c	 		\
		ft_itoa.c 				\
		ft_sqrt.c				\
		ft_memalloc.c			\
		ft_memccpy.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memdel.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_putchar_fd.c			\
		ft_putchar.c			\
		ft_putendl_fd.c			\
		ft_putendl.c			\
		ft_putnbr_fd.c			\
		ft_putnbr.c				\
		ft_putstr_fd.c			\
		ft_putstr.c				\
		ft_strcat.c				\
		ft_strchr.c				\
		ft_strclr.c				\
		ft_strcmp.c				\
		ft_strcpy.c				\
		ft_strdel.c				\
		ft_strdup.c				\
		ft_strndup.c			\
		ft_strequ.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strjoin.c			\
		ft_strnjoin.c			\
		ft_strlcat.c			\
		ft_strlen.c				\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strncat.c			\
		ft_strncmp.c			\
		ft_strncpy.c			\
		ft_strnequ.c			\
		ft_strnew.c				\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strsplit.c			\
		ft_strstr.c				\
		ft_strsub.c				\
		ft_strtrim.c			\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_checkspaces.c		\
		ft_intlen.c				\
		ft_range.c				\
		ft_abs.c				\
		ft_max.c				\
		ft_min.c				\
		ft_count_char.c			\
		ft_concat_params.c		\
		ft_sort_integer_table.c	\
		ft_create_elem.c		\
		ft_lstpush_back.c		\
		ft_lstpush_front.c		\
		ft_free_tab.c			\
		get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) $< -o $@ -I libft.h -g

$(OBJ) : libft.h

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
