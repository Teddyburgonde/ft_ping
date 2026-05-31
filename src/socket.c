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
