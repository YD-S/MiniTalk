/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:30:36 by ysingh            #+#    #+#             */
/*   Updated: 2022/11/10 20:38:40 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr(unsigned long long i)
{
	int	j;

	j = 0;
	while (i != 0)
	{
		i = i / 16;
		j++;
	}
	return (j);
}

int	ft_call_itoa(int c)
{
	int		len;
	char	*s;

	s = ft_itoa(c);
	len = ft_printf_putstr_fd(s, 1);
	free (s);
	return (len);
}

int	ft_printtype(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 's')
		len += ft_printf_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'c')
			len += ft_printf_putchar_fd(va_arg(args, int), 1);
	else if (c == 'x')
			len += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
			len += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
			len += ft_putdir(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (c == 'd' || c == 'i')
			len += ft_call_itoa(va_arg(args, int));
	else if (c == 'u')
		len += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
			len += ft_printf_putchar_fd('%', 1);
	return (len);
}
