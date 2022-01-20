# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 15:55:20 by mbarut            #+#    #+#              #
#    Updated: 2022/01/20 21:21:49 by mbarut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=webserv

DRIVER=driver/main.cpp

SRC=main.cpp

CC=clang++

CFLAGS_11= -Wall -Werror -Wextra -std=c++11 -g -o

CFLAGS_98= -Wall -Werror -Wextra -std=c++98 -g -o

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS_98) $(NAME)

c11:
	$(CC) $(SRC) $(CFLAGS_11) $(NAME)

c98:
	$(CC) $(SRC) $(CFLAGS_98) $(NAME)

clean:
	@rm -rf ./*.o ./webserv.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re