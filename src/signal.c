#include "../includes/ft_ping.h"

bool g_running = true;

void handler(int sig)
{
	(void)sig;

	g_running = false;
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