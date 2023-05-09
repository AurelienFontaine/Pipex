# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:09:26 by afontain          #+#    #+#              #
#    Updated: 2023/05/09 14:05:21 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

SRCS_DIR = srcs/

GNL_DIR = GNL/

SRCS =		${SRCS_DIR}main.c \
			${SRCS_DIR}split.c \
			${SRCS_DIR}utils.c \
			${GNL_DIR}get_next_line.c \
			${GNL_DIR}get_next_line_utils.c \
			
_DEPS =		pipex.h

INCL =		./includes/

DEPS =		$(patsubst %,$(INCL)/%,$(_DEPS))

OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

.c.o:		${DEPS} 
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

		

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME}
#		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:		${NAME}

clean:		
		${RM} ${OBJS}
#        make clean -C

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} 

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re