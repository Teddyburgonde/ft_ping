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

char	*get_destination(int argc, char **argv);
struct addrinfo	*hostname_to_ip(char *hostname);
char	*ip_to_str(struct addrinfo *results);
int		is_root(void);

#endif