#include "../include/libip.h"


#define PORT 5000

int close_sock(int sock_fd,int code)
{
    close(sock_fd);
    return (code);
}

int client(void)
{
    int sock;
    int r;
    char *line;
    struct sockaddr_in addr;

    sock = socket(PF_INET,SOCK_STREAM, 0);
    if(sock == -1)
    {
        perror("erreur socket");
        return (0);
    }
    printf("Socket crée avec succes\n");
    ft_memset(&addr, 0x0, sizeof(struct sockaddr_in));
    addr.sin_port = ft_htons_v2(PORT);
    addr.sin_family = PF_INET;
    ft_inet_pton(AF_INET, "192.168.1.2", &addr.sin_addr);

    if((r = connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in))) < 0)
    {
        perror("erreur connection");
        return (close_sock(sock, errno));
    }
    printf("Connection au port: %d\n", PORT);

    while (1)
    {
       line = get_next_line(1);
        if(!line)
            return (close_sock(sock, errno));

        write(sock, line, ft_strlen(line));
    }
    
    

    close(sock);
    return (1);
}

int main(void)
{

    client();
    
    return (0);
}