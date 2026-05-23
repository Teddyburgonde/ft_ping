# ft_ping - Notions importantes

## Ping
C'est une commande qui envoie un message à une adresse (ex: google.com) et attend une réponse.
Cela sert à savoir si une machine est joignable sur le réseau, et combien de temps le message met pour faire l'aller-retour.

---

## Composition d'un paquet
- **L'en-tête (header)** : contient les infos pour acheminer le paquet (adresse de départ, adresse d'arrivée, etc.)
- **Les données (payload)** : c'est le contenu, ce qu'on veut vraiment envoyer.

### Payload
Dedans il y a des données sans aucune importance. Ce qui compte pour ping c'est uniquement :
- Est-ce que le paquet est arrivé ?
- En combien de temps ?

---

## Exemple de sortie ping
```
PING google.com (142.251.142.14): 56 data bytes
64 bytes from 142.251.142.14: icmp_seq=0 ttl=117 time=15.109 ms
```

| Champ | Signification |
|---|---|
| `ping google.com` | J'envoie un paquet vers google.com |
| `142.251.142.14` | Adresse IP de google.com |
| `56 data bytes` | La taille du payload |
| `64 bytes` | La taille du paquet reçu (payload + header) |
| `icmp_seq=0` | Le numéro du paquet |
| `ttl=117` | Compteur qui diminue de 1 à chaque routeur. Quand il atteint 0, le paquet est détruit |
| `time=15.109ms` | Le temps aller-retour du paquet |

---

## ICMP
Protocole utilisé par ping pour envoyer ses paquets.
- **Echo Request** → j'envoie
- **Echo Reply** → je reçois

---

## Socket
C'est une porte de communication entre mon programme et un réseau.

**Raw socket** → c'est une socket où je construis moi-même le header ICMP.

```c
int rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
if (rawSocket < 0)
{
    perror("socket() error");
    exit(2);
}
printf("OK: a raw socket is created.\n");
```

---

## Structure d'un paquet ICMP
- **Header ICMP**
- **Payload**

### Header ICMP
| Champ | Rôle |
|---|---|
| `type` | Echo Request ou Echo Reply |
| `code` | Précision sur le type |
| `checksum` | Vérifier que le paquet n'est pas corrompu |
| `id` | Identifiant du paquet |
| `sequence` | Numéro du paquet (0, 1, 2, 3...) |

---

## Structure d'un header IP
| Champ | Rôle |
|---|---|
| `version` | IPv4 ou IPv6 |
| `ttl` | Le compteur |
| `protocol` | Quel protocole est dans le payload (ICMP, TCP, UDP...) |
| `saddr` | Adresse IP source (la mienne) |
| `daddr` | Adresse IP destination (google.com) |
| `check` | Le checksum du header IP |

---

## getaddrinfo
Permet de transformer un nom de domaine en adresse IP.
```
google.com → 172.217.22.110
```

---

## sendto
Fonction qui permet d'envoyer un paquet sur le réseau.

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

---

## Les signaux en C
Permet de gérer le Ctrl+C pour que le programme ne s'arrête pas brutalement.
Il affiche un résumé :
```
--- google.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 15ms
```

### Ce résumé contient :
- Combien de paquets envoyés
- Combien de paquets reçus
- Le pourcentage de paquets perdus
- Le temps min/max/avg

---

## Les privilèges root
Pour lancer la commande ping il faut être root.
On vérifie avec :
```c
if (getuid() != 0)
{
    printf("ft_ping: must be run as root\n");
    exit(1);
}
```

---

## Ordre d'exécution
```
1. getaddrinfo()  → transformer google.com en adresse IP
2. socket()       → créer la raw socket
3. sendto()       → envoyer le paquet
4. recvfrom()     → recevoir la réponse
```


## Structure

ft_ping/
├── Makefile
├── includes/
│   └── ft_ping.h
└── src/
    ├── main.c          -> point d'entrée, vérification root, parsing args
    ├── socket.c        -> création de la raw socket
    ├── dns.c           -> getaddrinfo (nom de domaine → IP)
    ├── packet.c        -> construction du header ICMP + checksum
    ├── ping.c          -> sendto + recvfrom + gettimeofday
    └── signal.c        -> gestion du SIGINT + affichage des statistiques

