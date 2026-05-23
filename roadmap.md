Étape 1 : Mise en place

Créer la structure du projet (fichiers, Makefile)
Vérifier que l'utilisateur est root (getuid)
Parser les arguments (ft_ping google.com, options -v et -?)

Étape 2 : Résolution du nom de domaine

Utiliser getaddrinfo pour convertir google.com en IP

Étape 3 : Créer la raw socket

Ouvrir la socket avec IPPROTO_ICMP

Étape 4 : Construire le paquet ICMP

Remplir les champs du header ICMP (type, code, id, sequence, checksum)
Calculer le checksum

Étape 5 : Envoyer et recevoir

gettimeofday + sendto + recvfrom + gettimeofday
Calculer et afficher le temps

Étape 6 : Gestion du Ctrl+C

Intercepter SIGINT
Afficher les statistiques finales

Étape 7 : Tests et corrections
