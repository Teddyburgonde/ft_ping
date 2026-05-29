#include "../includes/ft_ping.h"

/*
** Envoie un paquet ICMP Echo Request vers la destination.
** Quitte le programme si l'envoi echoue.
*/
static void send_ping(int raw_socket, struct icmphdr *icmphdr, struct sockaddr *addr)
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
** Recupere le TTL depuis le header IP du paquet reçu.
** Retourne le nombre d'octets reçus ou -1 en cas d'erreur.
*/
static int receive_ping(int raw_socket, struct sockaddr *addr,  int *ttl)
{
	int nb_octets;
	char buffer[1024];
	socklen_t addr_len = sizeof(*addr);
	struct iphdr *ip_header = (struct iphdr *)buffer;
	
	nb_octets = recvfrom(raw_socket, buffer, sizeof(buffer), 0, addr, &addr_len);
	if (nb_octets == -1)
	{
		perror("recvfrom");
		return (-1);
	}
	*ttl = ip_header->ttl;
	struct icmphdr *icmp = (struct icmphdr *)(buffer + 20);
	if (icmp->un.echo.id == getpid())
	{
		return nb_octets;
	}
	return (-1);
}


/*
** Boucle principale de ft_ping.
** Envoie un paquet ICMP Echo Request chaque seconde et affiche le resultat.
** S'arrete proprement sur Ctrl+C via le signal SIGINT.
*/
void	ping_loop(int raw_socket, struct sockaddr *addr, char *hostname, char *ip, t_stats *stats)
{	
	int sequence;
	struct icmphdr icmphdr;
	int nb_bytes;
	int ttl;
	struct timeval start;
	struct timeval end;
	double time_result;

	sequence = 0;
	time_result = 0;
	signal(SIGINT, handler);
	printf("PING %s\n (%s): 56 data bytes ",  hostname, ip);
	while (g_running)
	{
		build_icmp_header(&icmphdr, sequence);
		gettimeofday(&start, NULL);
		send_ping(raw_socket, &icmphdr, addr);
		stats->packets_sent++;
		nb_bytes = receive_ping(raw_socket, addr, &ttl);
		gettimeofday(&end, NULL);
		time_result = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        if (nb_bytes != -1)
		{
			stats->packets_received++;
            if (stats->time_min == 0 || time_result < stats->time_min)
				stats->time_min = time_result;
            if (time_result > stats->time_max)
				stats->time_max = time_result;
			stats->time_total += time_result;
			printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", nb_bytes, ip, sequence, ttl, time_result);
		}
		sequence++;
		sleep(1);
	}
	
}




