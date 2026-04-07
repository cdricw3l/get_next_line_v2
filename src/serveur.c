#include "../include/libip.h"

int serveur()
{

    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket serveur error");
        return (-1);
    }
    

    return (1);
}