/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:36:14 by ecabanas          #+#    #+#             */
/*   Updated: 2022/02/13 10:30:09 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(sizeof (char) * i + 1);
	i = 0;
	if (!ptr)
		return (0);
	else
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
}
