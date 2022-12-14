#include "../includes/minitalk.h"

void    encode(int pid, char *str)
{
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
{
    pid_t   pid;

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