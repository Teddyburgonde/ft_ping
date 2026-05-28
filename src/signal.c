#include "../includes/ft_ping.h"

void handler(int sig)
{
	(void)sig;
	printf("\nArrêt propre du programme\n");
}


// Nombre de paquets envoyés
// Nombre de paquets reçus
// Les temps min/max/avg


// // Signaux
// void handler(int signum)
// {
// 	if (signum == SIGINT)
// 		pingloop = 0;
// 	else if (signum == SIGALRM)
// 		send_packet = 1;
// }

// 	signal(SIGINT, &handler);
// 	signal(SIGALRM, &handler);


// declarer g_stats en variable globale