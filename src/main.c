#include "../includes/ft_ping.h"

int	main(int argc, char **argv)
{
	struct addrinfo *results;
	int verbose;
	char *destination;
	char *ip;

	results = NULL;
	verbose = 0;
	ip = NULL;
	destination = NULL;
	parse_args(argc, argv);
	destination = get_destination(argc, argv);
	results = hostname_to_ip(destination);
	if (results == NULL)
	{
    	printf("Error, hostname_to_ip failed\n");
    	return (1);
	}
	ip = ip_to_str(results);
	if (strcmp(argv[1], "-v") == 0)
    	verbose = 1;
	printf("verbose: %d\n", verbose);
	printf("ip: %s\n", ip);

	freeaddrinfo(results);
}
