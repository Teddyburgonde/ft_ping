#include "../includes/ft_ping.h"
#include <string.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"
#define RED "\033[0;31m"

/*
cc -Wall -Werror -Wextra -g src/tests.c src/dns.c -o test_bin -I includes && ./test_bin google.com

tests:
- get_destination ✅
- hostname_to_ip ✅
- ip_to_str ✅

sudo ./test_bin google.com
Tests:
- is_root ✅
*/

int main(int argc, char **argv)
{
	char *destination = get_destination(argc, argv);
	struct addrinfo *results = hostname_to_ip(destination);
	char *ip = ip_to_str(results);
	
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

	freeaddrinfo(results); // liberation de la memoire.
}
	