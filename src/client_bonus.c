/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:05 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/03 13:03:55 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	print_speed(size_t str)
{
	int	i;

	i = 0;
	if (str < 1000)
		i = 30;
	else if (str >= 1000)
		i = 300;
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
			{
				if (kill(pid, SIGUSR1) == -1)
					err_message("non existant pid");
			}
			else if (((unsigned char)str[i] >> bits & 1) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					err_message("non existant pid");
			}
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

	if (argc != 3)
		err_message("argc != 3. Check that the server is running.");
	if (!ft_atoi(argv[1], &pid))
		err_message("Wrong pid argument");
	if (!pid)
		err_message("pid not provided");
	if (ft_strlen(argv[2]) == 0)
		err_message("NULL string");
	init_sig(SIGUSR1, &confirmation_handler);
	encode(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
