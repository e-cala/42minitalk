#include "../includes/minitalk.h"
#include <stdio.h>

void    my_handler(int sig, siginfo_t *info, void *context)
{
    static unsigned char    c;
    static int              size;

    (void) context;
    if (sig == SIGUSR2)
        sig = 0;
    else if (sig == SIGUSR1)
        sig = 1;

    if (c == 0 && size == 0)
        size = 8;
    size--;
    c += (sig & 1) << size;
    if (size == 0)
    {
        if (!c)
        {
            ft_putchar_fd('\n', 1);
            kill(info->si_pid, SIGUSR1);
        }
        ft_putchar_fd(c, 1);
        size = 8;
        c = 0;
    }
}

void    put_pid(pid_t pid)
{
    ft_putstr_fd("PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putstr_fd("\n", 1);
}

int main(int argc, char *argv[])
{
    struct sigaction    act;
    pid_t               pid;

    (void)argc;
    (void)argv;
    pid = getpid();
    put_pid(pid);

    act.sa_sigaction = my_handler;
    act.sa_flags = SA_SIGINFO;

    while(1)
    {
        if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0)
        {
            ft_putendl_fd("An error has ocurred", 1);
            exit(EXIT_FAILURE);
        }
        pause();
    }

    return (0);
}