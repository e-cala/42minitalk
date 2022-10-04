#include "../includes/minitalk.h"

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putnbr_fd("Received!");
}

int	main(void)
{
	signal(SIGUSR1, my_handler);
	return (0);
}
