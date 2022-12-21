/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:48:09 by ecabanas          #+#    #+#             */
/*   Updated: 2022/10/07 18:40:28 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
				kill(pid, SIGUSR1);
			else if (((unsigned char)str[i] >> bits & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(200);
		}
		i++;
	}
}

void	confirmation_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)sig;
	ft_putendl_fd("Signal Received!",1);
	exit(EXIT_SUCCESS);
} 

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		err_message("Did not provide the right amount of parameters. Check that the server is running.");
	if (!ft_atoi(argv[1], &pid))
		err_message("Wrong pid argument");
	if (!pid)
		err_message("pid not provided");
	init_sig(SIGUSR1, &confirmation_handler);
	encode(pid, argv[2]);
 	while (1)
		pause();
	return (0);
}
