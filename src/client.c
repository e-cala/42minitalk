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

static void	encode(char *str, pid_t pid)
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
			usleep(100);
		}
		i++;
	}
}

static void	show_message(pid_t pid)
{
	ft_putstr_fd("Sending data to: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putendl_fd("..", 1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	show_message(pid);
	if (!pid)
		err_message();
	encode(argv[2], pid);
	while (1)
		usleep(100);
	return (0);
}
