/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:24:33 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/07 18:48:07 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	my_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static size_t			size;

	(void) context;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	if (c == 0 && size == 0)
		size = 8;
	size--;
	c += (sig & 1) << size;
	if (size == 0)
	{
		if (!c)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		ft_putchar_fd(c, 1);
		size = 8;
		c = 0;
	}
}

static void	show_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	act;

	show_pid();
	ft_memset(&act, '\0', sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = my_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
			err_message();
		sleep(2);
	}	
	return (0);
}
