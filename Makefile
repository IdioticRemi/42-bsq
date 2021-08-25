SRCS	= ./lib/chars.c ./lib/io.c ./lib/print.c ./lib/strings.c ./src/algo.c ./src/main.c ./src/parsing.c ./src/print_solution.c ./src/verif_grid_opti.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Wall
NAME	= bsq

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -I includes -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

norm:
	find . -type f -name "*.c" -exec norminette -R CheckDefine {} +

re: fclean all