/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:05 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/04 11:07:47 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	print_speed(size_t str)
{
	int	i;

	i = 0;
	if (str < 1000)
		i = 30;
	else if (str < 10000)
		i = 50;
	else if (str < 50000)
		i = 150;
	else if (str >= 50000)
		i = 1000;
	return (i);
}

static void	encode(int pid, char *str)
{
	size_t	i;
	size_t	bits;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if (((unsigned char)str[i] >> bits & 1) == 1)
				tern_int(kill(pid, SIGUSR1) == -1, "non existant pid");
			else if (((unsigned char)str[i] >> bits & 1) == 0)
				tern_int(kill(pid, SIGUSR2) == -1, "non existant pid");
			usleep(print_speed(len));
		}
		i++;
	}
}

void	confirmation_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)sig;
	ft_putendl_fd("Signal Received!", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	tern_int(argc != 3, "argc != 3. Check that the server is running.");
	tern_int(!ft_atoi(argv[1], &pid), "Wrong pid argument");
	tern_int(!pid, "pid not provided");
	tern_int(ft_strlen(argv[2]) == 0, "NULL string");
	init_sig(SIGUSR1, &confirmation_handler);
	encode(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
