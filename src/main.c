#include "../includes/ft_ping.h"

int	main(int argc, char **argv)
{
	struct addrinfo *results;
	int verbose;
	char *destination;
	char *ip;
	t_stats stats;
	int raw_socket;


	memset(&stats, 0, sizeof(stats));
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
	raw_socket = create_raw_socket();
	g_stats = &stats;
	ping_loop(raw_socket, results->ai_addr, destination, ip, &stats);
	freeaddrinfo(results);

	return (0);
}
