#include "../include/libip.h"

#define PORT 5000

int serveur()
{

    int sock;
    int sock_com;
    char *line;
    socklen_t len;
    struct sockaddr_in ad;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket serveur error");
        return (-1);
    }
    printf("socket %d crée\n", sock);
    ft_memset(&ad,0x0,sizeof(struct sockaddr_in));
    ad.sin_family = AF_INET;
    ad.sin_port = ft_htons_v2(5000);
    ad.sin_addr.s_addr = htonl(INADDR_ANY);
    len = sizeof(struct sockaddr_in);
    if(bind(sock,(struct sockaddr *)&ad, len) < 0)
    {
        perror("bind error");
        close(sock);
        return (errno);
    }

    printf("socket %d attachée\n", sock);

    if(listen(sock, 5) < 0)
    {
        perror("listen error");
        close(sock);
        return (errno);
    }

    while (1)
    {
        printf("serveur en ecoute sur le port: %d\n", PORT);
        sock_com = accept(sock, (struct sockaddr *)&ad, &len);
        if(sock_com < 0)
        {
            perror("accept error");
            close(sock);
            close(sock_com);
            return (errno);
        }

        line = get_next_line(sock_com);
        if(!line)
        {
            close(sock);
            close(sock_com);
            return (-1);
        }
        printf("message recu %s\n", line);
        write(sock_com, "ok\n", 3);
        close(sock_com);
        
    }
    
    return (1);
}

int main(void)
{
    serveur();
    return (0);
}