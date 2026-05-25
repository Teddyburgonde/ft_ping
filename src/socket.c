

// ## Socket
// C'est une porte de communication entre mon programme et un réseau.

// **Raw socket** → c'est une socket où je construis moi-même le header ICMP.

// ```c
// int rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
// if (rawSocket < 0)
// {
//     perror("socket() error");
//     exit(2);
// }
// printf("OK: a raw socket is created.\n");
// ```