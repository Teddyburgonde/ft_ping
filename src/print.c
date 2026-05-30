#include "../includes/ft_ping.h"

/*
** Affiche les statistiques finales apres l'arret du programme.
** Nombre de paquets envoyes/recus, pourcentage de perte et temps min/avg/max.
*/
void	print_stats(t_stats *stats, char *hostname)
{
	double	average;
	double	loss;

	loss = ((stats->packets_sent - stats->packets_received) * 100) / stats->packets_sent;
	average = stats->time_total / stats->packets_received;
	printf("--- %s ping statistics ---\n", hostname);
	printf("%d  packets transmitted, %d received, %.0f%% packet loss\n", stats->packets_sent, stats->packets_received, loss);
	printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n", stats->time_min, average, stats->time_max);
}

/*
** Affiche la ligne d'entete de ping avec les informations detaillees.
** Utilisee quand l'option -v est activee.
*/
void	print_verbose(char *hostname, char *ip_str, int payload_size)
{
	printf("PING %s (%s): %d data bytes, id 0x%x = %d \n", hostname, ip_str, payload_size, getpid(), getpid());
}
