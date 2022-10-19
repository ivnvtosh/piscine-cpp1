# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 02:30:17 by ccamie            #+#    #+#              #
#    Updated: 2022/10/19 14:37:54 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

CC			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

CXXFLAGS	=	

.SUFFIXES	:
.SUFFIXES	:	.cpp .o

.PHONY		:	all clean fclean re check

NAME		=	megaphone.out
SOURCE		=	megaphone.cpp
OBJECT		=	megaphone.o

RM			=	rm -f

TEST_N		=	test.out
TEST_S		=	test.cpp
TEST_O		=	test.o

%.o			:	%.c
				$(CC) $(CPPFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJECT)
				$(CC) $(CXXFLAGS) $(OBJECT) -o $(NAME)

check		:	$(TEST_N)
				@./$(TEST_N)

$(TEST_N)	:	$(TEST_O)
				$(CC) $(CXXFLAGS) $(TEST_O) -o $(TEST_N)

clean		:
				$(RM) $(OBJECT)

fclean		:
				$(RM) $(OBJECT)
				$(RM) $(NAME)

re			:	fclean all
