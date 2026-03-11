CC=cc
NAME_ASSER=assertions/assertions
NAME=gnl
GFLAGS=-Wall -Wextra -Werror
SRCS_GNL=get_next_line.c \
	 get_next_line_utils.c
SRCS_ASSER=assertions/assertions.c
SRCS_MAIN=main.c

OBJS_GNL= ${SRCS_GNL:.c=.o}
OBJS_MAIN= ${SRCS_MAIN:.c=.o}
OBJS_ASSER= ${SRCS_ASSER:.c=.o}
COM=GNL_V2

%.o:%.c
	${CC} -c ${GFLAGS} $^ -o $@

${NAME}: ${OBJS_MAIN} ${OBJS_GNL}
	${CC} ${GFLAGS} ${OBJS_MAIN} ${OBJS_GNL} -o ${NAME}

${NAME_ASSER}: ${OBJS_GNL} ${OBJS_ASSER}
	${CC} ${GFLAGS} ${OBJS_GNL} ${OBJS_ASSER} -o ${NAME_ASSER}

run: ${NAME}
	./${NAME}

as: ${NAME_ASSER}
	leaks --atExit -- ./${NAME_ASSER}

clean:
	rm -f ${OBJS_GNL} ${OBJS_ASSER} ${OBJS_MAIN}

fclean: clean
	rm -f ${NAME} ${NAME_ASSER}

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}

re: fclean ${NAME}