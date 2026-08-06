# Cartographie Réseau lapleiade : Exploration et Analyse avec le Terminal

## Postulat :

Je suis sur une machine connectée à un réseau local via Ethernet. La machine dispose d'un terminal, de l'éditeur de texte nano. Je n'ai pas accès à des outils graphiques ou à des interfaces spécialisées, ce qui limite les options disponibles.

A l'aide de mes compétences techniques en réseau et systèmes et programmation c/c++ , mon objectif est de cartographier le réseau local, c'est-à-dire d’identifier les autres machines connectées, les dispositifs réseau, leurs adresses IP et MAC, et obtenir des informations sur les services disponibles sur ces hôtes.

Je vais effectuer une reconnaissance active et passive du réseau pour obtenir un aperçu global de son architecture et de ses équipements au travers l'envoi de paquet d'apres les differente couche de reseau analysé.

# Chaque abstraction doit être reconstruite au moins une fois.

Aucun fichier d'en-tête réseau n'est autorisé pour la soumission. 

```c

Forbiden:

#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>

```

Chaque paquet et chaque fonction dois etre construite manuellement. Il est en revanche possible dans le cas de test unitaire , d'effectuer des comparaison entre le fonctionnement des fontions orignal et des fonction construite

```c

assert(ft_inet_addr("127.0.0.1") == inet_addr("127.0.0.1"));
assert(ft_inet_addr("192.168.1.42") == inet_addr("192.168.1.42"));
assert(ft_inet_addr("8.8.8.8") == inet_addr("8.8.8.8"));


```

## À utiliser
    socket()
    bind()
    listen()
    accept()
    connect()
    send()
    recv()
    endto()
    recvfrom()
    setsockopt()
    getsockopt()
    epoll_*()
    poll()
    select()
## À reconstruire
    inet_addr()
    inet_ntoa()
    inet_pton()
    inet_ntop()
    htons()
    htonl()
    ntohs()
    ntohl()
    checksum()
    les en-têtes (ethernet, arp, ipv4, icmp, udp, tcp)
    les sérialisations/désérialisations des paquets


