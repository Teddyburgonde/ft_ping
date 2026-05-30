#include "../includes/ft_ping.h"

/*
** Calcule le checksum ICMP en additionnant les donnees par mots de 16 bits (2 octets mis côte à côte),
** en gerant le depassement, puis en inversant les bits du resultat.
*/
static uint16_t calculate_checksum(void *data, int len)
{
	uint32_t sum; 
	
	sum = 0;
	uint16_t *ptr = (uint16_t *)data;
	while (len > 1)
	{
		sum += *ptr;
		ptr++;
		len-= 2;
	}
	if (len == 1) // si c'est un nombre d'octets impair il restera un octet à additionner 
		sum += *(uint8_t *)ptr;
	sum = (sum >> 16) + (sum & 0xFFFF);

	return ~sum;
}


/*
** Remplit les champs du header ICMP pour un Echo Request.
** Le checksum est mis a 0 avant d'etre calcule sur le header complet.
*/
void    build_icmp_header(struct icmphdr *icmphdr, int sequence)
{
	icmphdr->type = ICMP_ECHO; 
	icmphdr->code = 0;
	icmphdr->checksum = 0;
	icmphdr->un.echo.id = getpid();
	icmphdr->un.echo.sequence= sequence;
	icmphdr->checksum= calculate_checksum(icmphdr, sizeof(struct icmphdr));
}

