#include "../includes/minitalk.h"

static void	encode(char *str, pid_t pid)
{
	size_t i;
	size_t bits;
	size_t len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if (((unsigned char)str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else if (((unsigned char)str[i] >> bits && 1) == 0)
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}
/*
static void	ft_handler(int signum)
{
	(void) signum;
	ft_putendl_fd("Signal Received!",1);
	exit(EXIT_SUCCESS);
}
*/
int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_putstr_fd("Sending data to : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putendl_fd("..", 1);
	if (!pid)
	{
		ft_putendl_fd("An error has ocurred", 1);
		exit(EXIT_FAILURE);	
	}
	encode(argv[2], pid);
	/*while (1)	
		usleep(100);*/
	return (0);
}
