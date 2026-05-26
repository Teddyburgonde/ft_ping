#include "../includes/ft_ping.h"

/*
C'est une socket où je construis moi-même le header ICMP
*/
int create_raw_socket(void)
{
	int raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (raw_socket < 0)
	{
		perror("socket() error");
		exit(2);
	}
	return raw_socket;
}
