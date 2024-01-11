# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 17:26:50 by nhirzel           #+#    #+#              #
#    Updated: 2022/02/25 17:26:53 by nhirzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		=	main.c \
			verifarg.c \
			initall.c \
			life.c \
			outils.c \
			philosophers.c \
		  

OBJS		= ${SRCS:.c=.o}

INCLUDE		= -lpthread

RM			= rm -f

NAME		= philo

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${INCLUDE} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
