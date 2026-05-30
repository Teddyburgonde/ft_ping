#include "../includes/ft_ping.h"
#include <string.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"
#define RED "\033[0;31m"

/*
cc -Wall -Werror -Wextra -g src/tests.c src/dns.c src/parsing.c src/socket.c src/packet.c src/print.c -o test_bin -I includes && ./test_bin google.com


tests:
- get_destination ✅
- hostname_to_ip ✅
- ip_to_str ✅
- verbose / verbose2 ✅ 
- create_raw_socke ❓ Il faut etre root
- build_icmp_header ✅
- print_verbose ✅
- pinrt_stats ✅

sudo ./test_bin google.com
Tests:
- is_root ✅
*/



int main(int argc, char **argv)
{
	char *destination = get_destination(argc, argv);
	struct addrinfo *results = hostname_to_ip(destination);
	char *ip = ip_to_str(results);
	char *fake_argv[] = {"ft_ping", "-v", "google.com"};
	struct icmphdr icmphdr;

	// A TESTER DANS LA VM
	// int	verif_create_raw_socket;

	// verif_create_raw_socket = create_raw_socket(); 
	// if (verif_create_raw_socket >= 0)
	// {
	// 	printf(GREEN "✅ Success, create_raw_socket\n" RESET);
	// }
	// else
	// {
    // 	printf(RED "❌ ERROR, create_raw_socket\n" RESET);
	// }


	build_icmp_header(&icmphdr, 1);
	if (icmphdr.type == ICMP_ECHO && icmphdr.un.echo.sequence == 1)
    	printf(GREEN "✅ Success, build_icmp_header\n" RESET);
	else
    	printf(RED "❌ ERROR, build_icmp_header\n" RESET);

	if (strcmp(fake_argv[1], "-v") == 0)
	{
		printf(GREEN "✅ Success, verbose\n" RESET);
	}
	else
	{
		printf(RED "❌ ERROR, verbose\n" RESET);
	}
	char *fake_argv_no_v[] = {"ft_ping","google.com"};
	if (strcmp(fake_argv_no_v[1], "-v") != 0)
	{
		printf(GREEN "✅ Success, verbose2\n" RESET);
	}
	else
	{
		printf(RED "❌ ERROR, verbose2\n" RESET);
	}
	// int value_is_root;

	// value_is_root = is_root();
	// if (value_is_root == true)
	// {
	// 	printf(GREEN "✅ Success, is_root\n" RESET);
	// }
	// else
	// {
	// 	printf(RED "❌ ERROR, is_root\n" RESET);
	// }

	if (strcmp(destination, "google.com") == 0)
	{
    	printf(GREEN "✅ Success, get_destination\n" RESET);
	}
	else
	{
    	printf(RED "❌ ERROR, get_destination\n" RESET);
	}
	if (ip != NULL)
	{
		printf(GREEN "✅ Success, hostname_to_ip\n" RESET);
		printf(GREEN "✅ Success, ip_to_str\n" RESET);
	}
	else
	{
		printf(RED "❌ ERROR, hostname_to_ip\n" RESET);
    	printf(RED "❌ ERROR, ip_to_str\n" RESET);
	}

	// printf("destination: %s\n", destination);
	// printf("ip: %s\n", ip);


	// Test print_verbose
	printf("\n--- Test print_verbose ---\n");
	print_verbose("google.com", "172.217.22.110", 56);

	// Test print_stats
	printf("\n--- Test print_stats ---\n");
	t_stats stats;
	memset(&stats, 0, sizeof(stats));
	stats.packets_sent = 4;
	stats.packets_received = 3;
	stats.time_min = 10.5;
	stats.time_max = 25.3;
	stats.time_total = 50.0;
	print_stats(&stats, "google.com");

	freeaddrinfo(results); // liberation de la memoire.
}
	