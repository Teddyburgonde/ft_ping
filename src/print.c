#include "../includes/ft_ping.h"

void print_stats(t_stats *stats, char *hostname)
{
	printf("--- %s ping statistics ---", hostname);
	printf("%s  %s %d", stats->packets_sent, stats->packets_received, pourcentage perte);
	printf("%d %d %d / %d (moyenne)", stats->time_min, stats->time_max, time_total, stats->packets_received);
}



// --- google.com ping statistics ---
// 4 packets transmitted, 4 received, 0% packet loss
// round-trip min/avg/max = 18.553/22.000/23.761 ms
// Pour ça tu as besoin de :

// g_stats->packets_sent → paquets envoyés
// g_stats->packets_received → paquets reçus
// Calculer le % de perte : (packets_sent - packets_received) / packets_sent * 100
// g_stats->time_min → temps minimum
// g_stats->time_max → temps maximum
// g_stats->time_total / packets_received → temps moyen



// void	print_verbose(char *hostname, char *ip_str, int payload_size)
// {
// 	// ping.ping_hostname -> le nom de domaine (ex: google.com)
// 	// ip_str -> l'adresse IP résolue
// 	// payload_size -> la taille du payload (56 par défaut)
// 	// getpid() -> l'id du processus
// }