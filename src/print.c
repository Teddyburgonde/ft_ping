#include "../includes/ft_ping.h"

void	print_stats(t_stats *stats, char *hostname)
{
        int average;
        int loss;
        
        loss = ((stats->packets_sent - stats->packets_received) * 100) / stats->packets_sent;
        average = stats->time_total / stats->packets_received;
	printf("--- %s ping statistics ---", hostname);
	printf("%s  %s %d", stats->packets_sent, stats->packets_received, loss);
	printf("%d %d %d / %d (average)", stats->time_min, stats->time_max, time_total, stats->packets_received);

}

/* A corriger 

Voici les corrections :Voici les corrections :
Problème 1 : average et loss doivent être double pas int pour avoir les décimales.
Problème 2 : les printf ont les mauvais formats. Voilà le bon affichage :
cprintf("--- %s ping statistics ---\n", hostname);
printf("%d packets transmitted, %d received, %d%% packet loss\n", 
    stats->packets_sent, stats->packets_received, loss);
printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n", 
    stats->time_min, average, stats->time_max);
Problème 3 : time_total → stats->time_total

*/


// void	print_verbose(char *hostname, char *ip_str, int payload_size)
// {
// 	// ping.ping_hostname -> le nom de domaine (ex: google.com)
// 	// ip_str -> l'adresse IP résolue
// 	// payload_size -> la taille du payload (56 par défaut)
// 	// getpid() -> l'id du processus
// }

