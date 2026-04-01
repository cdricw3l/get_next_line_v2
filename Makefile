CC				:= cc
NAME			:= gnl
NAME_BONUS		:= gnl_bonus
GFLAGS			:= -Wall -Wextra -Werror
SRCS_GNL		:= get_next_line.c \
	 			get_next_line_utils.c
SRCS_GNL_BONUS	:=get_next_line_bonus.c \
	 			get_next_line_utils_bonus.c

OBJS_GNL		:= ${SRCS_GNL:.c=.o}
OBJS_GNL_BONUS	:= ${SRCS_GNL_BONUS:.c=.o}
OBJS_MAIN		:= ${SRCS_MAIN:.c=.o}
COM				:=GNL_V2

%.o:%.c
	${CC} -c ${GFLAGS} $^ -o $@

${NAME}: ${OBJS_MAIN} ${OBJS_GNL}
	${CC} ${GFLAGS} ${OBJS_MAIN} ${OBJS_GNL} -o ${NAME}

bonus: ${OBJS_GNL_BONUS}
	${CC} ${GFLAGS} ${OBJS_GNL_BONUS} -o ${NAME_BONUS}

run: ${NAME}
	./${NAME}

clean:
	rm -f ${OBJS_GNL} ${OBJS_GNL_BONUS}

fclean: clean
	rm -f ${NAME}  ${NAME_BONUS}

re: fclean ${NAME}

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}
