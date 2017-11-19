# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	g++
#--------------Name-------------------------#
NAME	=	Colleen
MYPATH	=	$(HOME)
#--------------Sources----------------------#
SRCS	=	Colleen.cpp

CCFLAGS	=	-Wall -Wextra -Werror -g

OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

.PHONY: $(NAME) clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(NAME) -O3

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJS)
	
fclean:	clean
	@rm -f $(NAME)

re: fclean all