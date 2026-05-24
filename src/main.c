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

int	main()
{
	if (is_root() == false)
	{
		printf("ft_ping: must be run as root\n");
		exit(1);
	}
}


// ft_ping -v google.com, récupérer ces arguments.