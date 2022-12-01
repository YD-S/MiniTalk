/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:48:10 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/01 08:16:01 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, struct __siginfo *info, void *context)
{
	static int		i;
	static char		byte;

	(void) context;
	if (signal == SIGUSR1)
		byte |= 0b1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
		{
			ft_printf("\n");
			kill (info->si_pid, SIGUSR1);
		}
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t				i;
	struct sigaction	sig;

	i = getpid();
	ft_printf("PID : %d\n", i);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
		usleep(50);
	}
}
