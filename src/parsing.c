#include "../includes/ft_ping.h"

/* 
Permet de savoir si utilisateur est root.
*/
int	is_root(void)
{
	if (getuid() != 0)
	{
		return false;
	}
	return true;
}

/*
Récupere l'adresse du destinataire
*/
char	*get_destination(int argc, char **argv)
{
	if (argc == 2)
	{
		return argv[1];
	}
	if (argc == 3)
	{
		return argv[2];
	}
	return NULL;
}

/*
** Verifie que les arguments sont valides et que l'utilisateur est root.
** Quitte le programme si une erreur est detectee.
*/
void parse_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		printf("Error, Incorrect number of arguments\n");
		exit (1);
	}
	if (argc == 3)
	{
		if (strcmp(argv[1], "-v") != 0 && strcmp(argv[1], "-?") != 0)
		{
			printf("Error, ./ft_ping -v recipient\n");
			exit (1);
		}
	}
	if (is_root() == false)
	{
		printf("Error, ft_ping: must be run as root\n");
		exit (1);
	}
}
