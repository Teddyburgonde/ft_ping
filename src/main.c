#include "../includes/ft_ping.h"

// Permet de savoir si utilisateur est root.
int	is_root(void) 
{
	if (getuid() != 0)
	{
		return false;
	}
	return true;
}

int is_verbose(char* argv)
{
	if (strcmp(argv, "-v") == 0)
		return true;
	return false;
}


int	main(int argc, char **argv)
{
	int	verbose; 
	
	verbose = 0;
	if (argc < 2 || argc > 3)
	{
		printf("./ft_ping -v recipient");
		return (1);
	}
	if (is_verbose(argv[1]) == true)
	{
		verbose = 1;
	}
	else if (strcmp(argv[1],"-?") == 0)
	{

	}
	if (is_root() == false)
	{
		printf("ft_ping: must be run as root\n");
		return (1);
	}
}

