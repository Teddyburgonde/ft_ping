#include "../includes/ft_ping.h"

/*
Récupere l'adresse du destinataire
*/
char	*get_destination(int argc, char **argv)
{
	if (argc == 2)
	{
		return argv[1];
	}
	if (argc == 3)
	{
		return argv[2];
	}
	return NULL;
}

/*
Transforme le nom de domaine en binaire
*/
struct addrinfo	*hostname_to_ip(char *hostname)
{
	struct addrinfo	hints;
	struct addrinfo *results;
	int	status;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	status = getaddrinfo(hostname, NULL, &hints, &results);
	if (status != 0)
	{
		printf("ft_ping: %s: %s\n", hostname, gai_strerror(status));
		exit(1);
	}
	return results;
}

/*
Transforme le binaire en string lisible
*/
char	*ip_to_str(struct addrinfo *results)
{
	struct sockaddr_in	*ipv4;
	char				*ip_str;

	ipv4 = (struct sockaddr_in *)results->ai_addr;
	ip_str = inet_ntoa(ipv4->sin_addr);

	return ip_str;
}
