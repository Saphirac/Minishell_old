# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:46:31 by mcourtoi          #+#    #+#              #
#    Updated: 2023/01/09 13:44:30 by mcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

SRC_DIR = srcs
OBJ_DIR = objs

MAIN = main.c

SRCS =	\

OBJS = ${SRCS:.c=.o}
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJS))
OBJSMAIN = ${MAIN:.c=.o}
OBJSMAIN := $(addprefix $(OBJ_DIR)/, $(OBJSMAIN))

INC = ./includes

FLAGS = -Wall -Wextra -Werror -MMD -MP
LDFLAGS = -lreadline

${NAME}:    ${OBJS} ${OBJSMAIN}
	    ${CC} ${OBJS} ${OBJSMAIN} -o ${NAME}
	    ${CC} $^ -o ${NAME}

-include ${OBJ_DIR}/*.d

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p ${OBJ_DIR}
	${CC} -g3 ${FLAGS} ${LDFLAGS} -I${INC} -c $< -o $@

all:    ${NAME}

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re