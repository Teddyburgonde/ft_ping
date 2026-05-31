#include "../includes/ft_ping.h"

/*
C'est une socket où je construis moi-même le header ICMP
*/
int create_raw_socket(void)
{
	int raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	struct timeval timeout;

	raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (raw_socket < 0)
	{
		perror("socket() error");
		exit(2);
	}

	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	setsockopt(raw_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
	return raw_socket;
}


/*
** Modifie la valeur du TTL sur la socket.
** Permet de controler le nombre de sauts maximum du paquet.
*/
void    set_ttl(int raw_socket, int ttl)
{
    if (setsockopt(raw_socket, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) < 0)
    {
        perror("setsockopt TTL");
        exit(1);
    }
}

/*
** Recupere la valeur du TTL depuis les arguments.
** Retourne 64 par defaut si -ttl n'est pas specifie.
*/
int     get_ttl(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
		if (strncmp(argv[i], "--ttl=", 6) == 0)
            return (atoi(argv[i] + 6));
        i++;
    }
    return (64);
}