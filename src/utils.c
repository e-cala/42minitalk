/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:52:37 by ecabanas          #+#    #+#             */
/*   Updated: 2022/12/20 09:52:43 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	err_message(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sig != SIGUSR1 && sig != SIGUSR2)
		err_message("An error has ocurred");
	sigaction(sig, &act, NULL);
}