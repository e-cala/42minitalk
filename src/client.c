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

void    encode(int pid, char *str)
{
<<<<<<< HEAD
        int i;
        int bits;

        i = 0;
        while (str[i])
        {
            bits = 8;
            while (bits != 0)
            {
                bits--;
                if ((str[i] >> bits & 1) == 0)
                    kill(pid, SIGUSR2);
                else if ((str[i] >> bits & 1) == 1)
                    kill(pid, SIGUSR1);
                usleep(500);
            }
            i++;
        }     
}


int main(int argc, char *argv[])
=======
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
>>>>>>> 101c215c00472e88295e7e73f863096f19c82c18
{
    pid_t   pid;

<<<<<<< HEAD
    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    if (!pid)
    {
        ft_putendl_fd("An error has ocurred", 1);
        exit(EXIT_FAILURE);
    }
    encode(pid, argv[2]);

    return (0);
}
=======
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
>>>>>>> 101c215c00472e88295e7e73f863096f19c82c18
