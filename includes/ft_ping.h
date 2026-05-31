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
#include <signal.h>
#include <sys/time.h>
#include <math.h>

extern bool g_running;

typedef struct s_stats
{
	int		packets_sent;
	int		packets_received;
	double	time_min;
	double	time_max;
	double	time_total;
	double  time_total_sq;
} t_stats;


/* dns.c */
struct addrinfo	*hostname_to_ip(char *hostname);
char	*ip_to_str(struct addrinfo *results);


/* packet.c */
void    build_icmp_header(struct icmphdr *icmphdr, int sequence);


/* parsing.c */
char	*get_destination(int argc, char **argv);
void	parse_args(int argc, char **argv);
int		is_root(void);

/* ping.c */
void	ping_loop(int raw_socket, struct sockaddr *addr, char *hostname, char *ip, t_stats *stats, int verbose);

/* print.c */
void	print_stats(t_stats *stats, char *hostname);
void	print_verbose(char *hostname, char *ip_str, int payload_size);

/* signal.c */
void	handler(int sig);

/* socket.c */
int		create_raw_socket(void);


#endif
