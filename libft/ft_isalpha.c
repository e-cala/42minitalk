/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:52:51 by ecabanas          #+#    #+#             */
/*   Updated: 2022/01/25 16:45:33 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{	
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z' ))
		return (1);
	return (0);
}
