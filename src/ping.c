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

receive_ping -> reçoit la réponse et affiche le résultat




ping_loop -> la boucle principale qui appelle les deux



- gettimeofday + sendto + recvfrom + gettimeofday ❌
- Calculer et afficher le temps ❌



## recvfrom
Fonction qui permet de recevoir un paquet depuis le réseau.
> ⚠️ recvfrom est **bloquant** : le programme attend jusqu'à recevoir un paquet.

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

