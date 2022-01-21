# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 15:55:20 by mbarut            #+#    #+#              #
#    Updated: 2022/01/21 17:38:11 by mbarut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=webserv

SERVER=server.cpp

SRC=ft_memset.cpp

CC=clang++

CFLAGS= -Wall -Werror -Wextra -std=c++98 -g -o

all: $(NAME)

$(NAME):
	$(CC) $(SERVER) $(SRC) $(CFLAGS) $(NAME)

clean:
	@rm -rf ./*.o ./webserv.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re