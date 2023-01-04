/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:05:14 by ecabanas          #+#    #+#             */
/*   Updated: 2023/01/04 12:33:50 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

/*	utils.c		*/
int		tern_int(int condition, char *if_true);
void	err_message(char *str);
void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *));
#endif
