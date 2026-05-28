#include "../includes/ft_ping.h"

/*
** Envoie un paquet ICMP Echo Request vers la destination.
** Quitte le programme si l'envoi echoue.
*/
void send_ping(int raw_socket, struct icmphdr *icmphdr, struct sockaddr *addr)
{
	int statut;

	statut = sendto(raw_socket, icmphdr, sizeof(struct icmphdr), 0, addr, sizeof(*addr));
	if (statut == -1)
	{
		perror("sendto");
		exit(1);
	}
}

/*
** Attend et recupere un paquet ICMP sur le reseau.
** Verifie que le paquet appartient bien a mon ft_ping via le PID.
** Retourne le nombre d'octets reçus ou -1 en cas d'erreur.
*/
int receive_ping(int raw_socket, struct sockaddr *addr)
{
	int nb_octets;
	char buffer[1024];
	socklen_t addr_len = sizeof(*addr);

	nb_octets = recvfrom(raw_socket, buffer, sizeof(buffer), 0, addr, &addr_len);
	if (nb_octets == -1)
	{
		perror("recvfrom");
		return (-1);
	}
	struct icmphdr *icmp = (struct icmphdr *)(buffer + 20);
	if (icmp->un.echo.id == getpid())
	{
		return nb_octets;
	}
	return (-1);
}

#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void handler(int sig)
{
    (void)sig;
    printf("\nArrêt propre du programme\n");
}

void    ping_loop(int raw_socket, struct sockaddr *addr, char *hostname, char *ip)
{	
	char *destinataire;
	char *str;
	int start;
	int end;
	int sequence;

	destinataire = NULL;
	str = NULL;
	start = 0;
	end = 0;
	sequence = 0;
	int result ;
	result = 0;
	while (1)
	{
		signal(SIGINT, handler);
		destinataire = get_destination(argc, argv);
		str = ip_to_str(results);
		build_icmp_header(icmphdr, sequence);
		gettimeofday(start);
		// Je suis ici
		send_ping(raw_socket, struct icmphdr *icmphdr, addr);
		receive_ping(raw_socket, addr);
		gettimeofday(end);
		result = end - start;
		printf(result);
		sequence++;
		wait(1);
		printf("PING %s\n (%s): 56 data bytes ",  destinataire, str);
	}
}



Construire le header ICMP avec build_icmp_header
Démarrer le chronomètre
Envoyer le paquet avec send_ping
Recevoir la réponse avec receive_ping
Arrêter le chronomètre
Afficher le résultat
Incrémenter la sequence
Attendre 1 seconde



