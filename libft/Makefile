# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 12:01:32 by tmakgale          #+#    #+#              #
#    Updated: 2017/06/23 12:01:40 by tmakgale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS		= ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strsub.c \
		  ft_strcpy.c

OBJ		= $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):
		gcc -c -Wall -Werror -Wextra $(SRCS)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
