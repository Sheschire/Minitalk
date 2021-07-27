# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 16:24:58 by tlemesle          #+#    #+#              #
#    Updated: 2021/07/27 16:40:49 by tlemesle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=		gcc

CFLAGS 				= 		-Wall -Wextra -Werror
SERVER				=		server
SERVERO				= 		srcs/server.o 
SERVERC				= 		srcs/server.c

CLIENT				=		client
CLIENTO 			= 		srcs/client.o
CLIENTC				=		srcs/client.c

RM					= 		rm -f

all:		${SERVER} ${CLIENT}

${SERVER}:		${SERVERO}
					${CC} ${CFLAGS} -o ${SERVER} ${SERVERO}  ${OBJS} 

${CLIENT}:		${CLIENTO}
					${CC} ${CFLAGS} -o ${CLIENT} ${CLIENTO} ${OBJS}
clean:		
			${RM} ${SERVERO} ${CLIENTO}

fclean:		clean
			${RM} ${SERVER} ${CLIENT} ${SERVERO} ${CLIENTO}

re:			fclean all

.PHONY:		all clean fclean re