/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:30:08 by ysingh            #+#    #+#             */
/*   Updated: 2022/11/10 20:39:54 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	i;

	i = ft_get_nbr_hex(n);
	if (n > 15)
		ft_puthex(n / 16, base);
	ft_printf_putchar_fd(base[n % 16], 1);
	return (i);
}

int	ft_putdir(unsigned long long n, char *base)
{
	int	i;

	i = 0;
	i += ft_printf_putstr_fd ("0x", 1);
	if (n == 0)
		i += ft_printf_putchar_fd('0', 1);
	else
	{
		i += ft_get_ptr(n);
		ft_putptr(n, base);
	}
	return (i);
}

void	ft_putptr(unsigned long long n, char *base)
{
	if (n > 15)
		ft_putptr(n / 16, base);
	ft_printf_putchar_fd(base[n % 16], 1);
}

int	ft_get_nbr_hex(unsigned int i)
{
	int	j;

	j = 1;
	while (i >= 16)
	{
		i = i / 16;
		j++;
	}
	return (j);
}

int	ft_cont(unsigned int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}
