SRCS	= $(shell find . -type f -name "*.c")
#SRCS	= ./lib/chars.c ./lib/io.c ./lib/strings.c ./src/algo.c ./src/main.c ./src/parsing.c ./lib/print.c ./src/verif_grid_opti.c
CC		= gcc
CFLAGS	= -Wall -Wextra -Wall -g3
NAME	= bsq

${NAME}:
	${CC} ${CFLAGS} -I includes -o ${NAME} ${SRCS}

all: ${NAME}

fclean:
	rm -f ${NAME}

norm:
	find . -type f -name "*.c" -exec norminette -R CheckDefine {} +

re: fclean all
