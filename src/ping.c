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




ping_loop c'est la boucle principale de ft_ping. Elle doit :

Afficher la ligne de départ : PING google.com (172.217.22.110): 56 data bytes
Boucler indéfiniment jusqu'au Ctrl+C :

Construire le header ICMP avec build_icmp_header
Démarrer le chronomètre
Envoyer le paquet avec send_ping
Recevoir la réponse avec receive_ping
Arrêter le chronomètre
Afficher le résultat
Incrémenter la sequence
Attendre 1 seconde



La signature :
void    ping_loop(int raw_socket, struct sockaddr *addr, char *hostname, char *ip);

ping_loop -> la boucle principale qui appelle les deux



- gettimeofday + sendto + recvfrom + gettimeofday ❌
- Calculer et afficher le temps ❌




---

## gettimeofday
Fonction qui permet de mesurer le temps en C.
Exemple : `time=15ms`

### Principe
```
1. gettimeofday(start)
2. sendto()
3. recvfrom()
4. gettimeofday(end)
5. résultat = end - start
```

ping.c → sendto + recvfrom + gettimeofday

