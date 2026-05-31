#include "../includes/ft_ping.h"

/*
** Affiche les statistiques finales apres l'arret du programme.
** Nombre de paquets envoyes/recus, pourcentage de perte et temps min/avg/max.
*/
void	print_stats(t_stats *stats, char *hostname)
{
	double	average;
	double	loss;
	double stddev;
	
	loss = ((stats->packets_sent - stats->packets_received) * 100) / stats->packets_sent;
	average = stats->time_total / stats->packets_received;
	stddev = sqrt((stats->time_total_sq / stats->packets_received) - (average * average));
	printf("--- %s ping statistics ---\n", hostname);
	printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n", stats->packets_sent, stats->packets_received, loss);
	printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n", stats->time_min, average, stats->time_max, stddev);
}

/*
** Affiche la ligne d'entete de ping avec les informations detaillees.
** Utilisee quand l'option -v est activee.
*/
void	print_verbose(char *hostname, char *ip_str, int payload_size)
{
	printf("PING %s (%s): %d data bytes, id 0x%x = %d \n", hostname, ip_str, payload_size, getpid(), getpid());
}


// void	print_help(void)
// {
// 	Usage
//   ping [options] <destination>

// Options:
//   <destination>      dns name or ip address
//   -a                 use audible ping
//   -A                 use adaptive ping
//   -B                 sticky source address
//   -c <count>         stop after <count> replies
//   -D                 print timestamps
//   -d                 use SO_DEBUG socket option
//   -f                 flood ping
//   -h                 print help and exit
//   -I <interface>     either interface name or address
//   -i <interval>      seconds between sending each packet
//   -L                 suppress loopback of multicast packets
//   -l <preload>       send <preload> number of packages while waiting replies
//   -m <mark>          tag the packets going out
//   -M <pmtud opt>     define mtu discovery, can be one of <do|dont|want>
//   -n                 no dns name resolution
//   -O                 report outstanding replies
//   -p <pattern>       contents of padding byte
//   -q                 quiet output
//   -Q <tclass>        use quality of service <tclass> bits
//   -s <size>          use <size> as number of data bytes to be sent
//   -S <size>          use <size> as SO_SNDBUF socket option value
//   -t <ttl>           define time to live
//   -U                 print user-to-user latency
//   -v                 verbose output
//   -V                 print version and exit
//   -w <deadline>      reply wait <deadline> in seconds
//   -W <timeout>       time to wait for response

// IPv4 options:
//   -4                 use IPv4
//   -b                 allow pinging broadcast
//   -R                 record route
//   -T <timestamp>     define timestamp, can be one of <tsonly|tsandaddr|tsprespec>

// IPv6 options:
//   -6                 use IPv6
//   -F <flowlabel>     define flow label, default is random
//   -N <nodeinfo opt>  use icmp6 node info query, try <help> as argument

// For more details see ping(8).

// }