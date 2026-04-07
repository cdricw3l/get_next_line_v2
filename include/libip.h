#ifndef LIBIP_H
#define LIBIP_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "../libft/libft.h"
#include "../gnl/include/get_next_line.h"

#define ALL       0
#define PRIVATE_1 1
#define PRIVATE_2 2
#define PRIVATE_3 3
#define CUSTOM    4

#define LOW 0
#define UP 1


uint16_t ft_htons_v2(uint16_t port);
uint16_t ft_htons_v1(uint16_t port);

int ft_inet_pton(int familly, char *addr_str, struct in_addr *addr);

int client(void);

#endif