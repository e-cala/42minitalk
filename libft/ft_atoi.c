/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:47:57 by ecabanas          #+#    #+#             */
/*   Updated: 2022/03/01 18:41:40 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_separator(char c)
{
	if (c == ' ' || c == '\r' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str, pid_t *value)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (is_separator(str[i]))
			i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	*value = sign * num;
	return (1);
}
