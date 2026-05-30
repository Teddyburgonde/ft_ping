#include "../includes/ft_ping.h"

bool g_running = true;

void handler(int sig)
{
	(void)sig;

	g_running = false;
}
