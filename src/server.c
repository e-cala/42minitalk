/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:24:33 by ecabanas          #+#    #+#             */
/*   Updated: 2022/12/20 09:41:53 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	message_handler(int sig, siginfo_t *info, void *context)
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
	init_sig(SIGUSR1, &message_handler);
	init_sig(SIGUSR2, &message_handler);
	show_pid();
	while (1)
		pause();
	return (0);
}
