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
	printf("PING %s (%s): %d data bytes, id 0x%x = %d\n", hostname, ip_str, payload_size, getpid(), getpid());
}


/*
** Affiche l'aide et les options disponibles de ft_ping.
** Appellee quand l'option -? est detectee.
*/
void	print_help(void)
{
	printf("Usage: ft_ping [OPTION...] HOST ...\n");
	printf("Send ICMP ECHO_REQUEST packets to network hosts.\n");
	printf("\n");
	printf(" Options controlling ICMP request types:\n");
	printf("      --address              send ICMP_ADDRESS packets (root only)\n");
	printf("      --echo                 send ICMP_ECHO packets (default)\n");
	printf("      --mask                 same as --address\n");
	printf("      --timestamp            send ICMP_TIMESTAMP packets\n");
	printf("  -t, --type=TYPE            send TYPE packets\n");
	printf("\n");
	printf(" Options valid for all request types:\n");
	printf("\n");
	printf("  -c, --count=NUMBER         stop after sending NUMBER packets\n");
	printf("  -d, --debug                set the SO_DEBUG option\n");
	printf("  -i, --interval=NUMBER      wait NUMBER seconds between sending each packet\n");
	printf("  -n, --numeric              do not resolve host addresses\n");
	printf("  -r, --ignore-routing       send directly to a host on an attached network\n");
	printf("      --ttl=N                specify N as time-to-live\n");
	printf("  -T, --tos=NUM              set type of service (TOS) to NUM\n");
	printf("  -v, --verbose              verbose output\n");
	printf("  -w, --timeout=N            stop after N seconds\n");
	printf("  -W, --linger=N             number of seconds to wait for response\n");
	printf("\n");
	printf(" Options valid for --echo requests:\n");
	printf("\n");
	printf("  -f, --flood                flood ping (root only)\n");
	printf("      --ip-timestamp=FLAG    IP timestamp of type FLAG, which is one of\n");
	printf("                             \"tsonly\" and \"tsaddr\"\n");
	printf("  -l, --preload=NUMBER       send NUMBER packets as fast as possible before\n");
	printf("                             falling into normal mode of behavior (root only)\n");
	printf("  -p, --pattern=PATTERN      fill ICMP packet with given pattern (hex)\n");
	printf("  -q, --quiet                quiet output\n");
	printf("  -R, --route                record route\n");
	printf("  -s, --size=NUMBER          send NUMBER data octets\n");
	printf("\n");
	printf("  -?, --help                 give this help list\n");
	printf("      --usage                give a short usage message\n");
	printf("  -V, --version              print program version\n");
	printf("\n");
	printf("Mandatory or optional arguments to long options are also mandatory or optional\n");
	printf("for any corresponding short options.\n");
	printf("\n");
	printf("Options marked with (root only) are available only to superuser.\n");
	printf("\n");
	printf("Report bugs to <bug-inetutils@gnu.org>.\n");
}