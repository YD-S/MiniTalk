/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:48:13 by ysingh            #+#    #+#             */
/*   Updated: 2022/12/01 13:52:51 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal)
{
	(void)signal;
	ft_printf("\n ACK\n");
	exit (0);
}

void	sendbyte(char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c & (0b1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		j++;
	}
}

void	send(char *line, int pid)
{
	int	i;

	i = 0;
	while (line[i])
	{
		sendbyte(line[i], pid);
		usleep(50);
		i++;
	}
	sendbyte('\0', pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, handler);
		send(argv[2], ft_atoi(argv[1]));
		while (1)
			usleep(1);
	}
}
