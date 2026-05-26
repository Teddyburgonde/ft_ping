#ifndef FT_PING_H
#define FT_PING_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <netinet/ip_icmp.h>

/* dns.c */
struct addrinfo	*hostname_to_ip(char *hostname);
char	*ip_to_str(struct addrinfo *results);


/* parsing.c */
char	*get_destination(int argc, char **argv);
void	parse_args(int argc, char **argv);
int		is_root(void);



#endif
