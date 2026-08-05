NAME=workshop
CLT_NAME= client
SRV_NAME= serveur
CC= clang
GFLAGS= -Werror -Wextra -Wall -g
LIB= 	-Llibft -lft
SRCS= 	$(wildcard src/*.c)

SRCS_GNL := $(wildcard gnl/src/*.c)

SRCS_CLT= 	src/client.c \
			src/ft_htons.c \
			src/ft_inet_pton.c

SRCS_SRV= 	src/serveur.c \
			src/ft_htons.c \
			src/ft_inet_pton.c

SRCS_OBJ= $(SRCS:.c=.o)
GNL_OBJ= $(SRCS_GNL:.c=.o)
CLT_OBJ= $(SRCS_CLT:.c=.o)
SRV_OBJ= $(SRCS_SRV:.c=.o)
GCOM="default commit message"

%.o:%.c
	$(CC) $(GFLAGS)  -c $^ -o $@

$(NAME): $(SRCS_OBJ) $(LIBFT_DIR)
	$(CC) $(GFLAGS) $(SRCS_OBJ) $(LIB) -o $(NAME)

clean:
	rm -f $(GNL_OBJ) $(CLT_OBJ) $(SRV_OBJ)
	rm -rf *.dSYM

fclean: clean
	rm -f $(NAME) $(CLT_NAME) $(SRV_NAME)
r:
	./$(NAME)

re: fclean $(NAME)

clt: $(CLT_OBJ) $(GNL_OBJ)
	$(CC) $(GFLAGS) $(CLT_OBJ) $(GNL_OBJ) $(LIB) -o $(CLT_NAME)

srv: $(SRV_OBJ) $(GNL_OBJ)
	$(CC) $(GFLAGS) $(SRV_OBJ) $(GNL_OBJ) $(LIB) -o $(SRV_NAME)

git: fclean
	git add .
	git commit -m $(GCOM)
	git push origin $(shell git branch --show-current)

lib:
	cd libft && make bonus && make clean