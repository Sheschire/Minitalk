# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 16:24:58 by tlemesle          #+#    #+#              #
#    Updated: 2021/07/28 16:27:28 by tlemesle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		minitalk
CC					=		gcc

CFLAGS 				= 		-Wall -Wextra -Werror
SERVER				=		server
SERVERO				= 		srcs/server.o 
SERVERC				= 		srcs/server.c

CLIENT				=		client
CLIENTO 			= 		srcs/client.o
CLIENTC				=		srcs/client.c

UTILSO				=		srcs/utils.o
UTILSC				=		srcs/utils.c

RM					= 		rm -f

all:			${NAME}

${NAME}:		${SERVER} ${CLIENT}

${SERVER}:		${SERVERO}
					${CC} ${CFLAGS} -o ${SERVER} ${SERVERO} ${UTILSC} ${OBJS} 

${CLIENT}:		${CLIENTO}
					${CC} ${CFLAGS} -o ${CLIENT} ${CLIENTO} ${UTILSC} ${OBJS}
clean:
			${RM} ${SERVERO} ${CLIENTO}

fclean:		clean
			${RM} ${SERVER} ${CLIENT} ${SERVERO} ${CLIENTO}

re:			fclean all

.PHONY:		all clean fclean re