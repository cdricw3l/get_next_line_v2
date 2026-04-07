# Cartographie Réseau lapleiade : Exploration et Analyse avec le Terminal

## Postulat :

Je suis sur une machine connectée à un réseau local via Ethernet. La machine dispose d'un terminal, de l'éditeur de texte nano. Je n'ai pas accès à des outils graphiques ou à des interfaces spécialisées, ce qui limite les options disponibles.

A l'aide de mes compétences techniques en réseau et systèmes et programmation c/c++ , mon objectif est de cartographier le réseau local, c'est-à-dire d’identifier les autres machines connectées, les dispositifs réseau, leurs adresses IP et MAC, et obtenir des informations sur les services disponibles sur ces hôtes.

Je vais effectuer une reconnaissance active et passive du réseau pour obtenir un aperçu global de son architecture et de ses équipements au travers l'envoi de paquet d'apres les differente couche de reseau analysé.


## Exploration

### les sturctures:

La structure pour travailler avec des adresses ipv4 est la structure sockaddr_in

```
    struct sockaddr_in {

        sa_family_t    sin_family; 
        in_port_t      sin_port;
        struct in_addr sin_addr;
    };

    struct in_addr {
        uint32_t       s_addr;
    };

```

sin_family: famille de protocol d'adresse IP. Dans le cas de sockaddr_in la famille est toujour ipv4 soit : AF_INET.
sin_port: le port auquel nous souhaitons nous connecter. Attention à bien utiliser htonl.
sin_addr: structure qui contient l'adresse sous la forme d'un entier.


### les fonction

```

inet_pton(AF_INET, "216.58.192.3", &(sa.sin_addr));

```
inet_pton convertie une adresse ip (ipv4 ou ipv6) du format string vers le format __uint32_t.
Elle prend en parametre la famille de protocol d'adresse IP, l'adresse ip au format string et un pointeur vers une structure in_addr (ipv4) ou in6_addr (ipv6). "It returns 1 if the string was successfully interpreted, or 0 if the string is invalid." (man inet_pton).



```
uint16_t htons(uint16_t hostshort);

````
htonl prend en parametre et retourne un uint16_t. La valeur max d'un uint16_t est UINT16_MAX soit 65535.
La fonction inverse les deux octets de la valeur passée en parametre qui correspond au port auquel on veut ce connecter.

00000000 01011010 -> sortie_source -> entré_dest -> 01011010 00000000


8 16 24 32