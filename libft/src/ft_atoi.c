/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:16:55 by ysingh            #+#    #+#             */
/*   Updated: 2022/10/05 15:25:01 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sign(int sign);

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				sign;

	num = 0;
	i = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (ft_isdigit(str[i]) == 0 && ft_isdigit(str[i + 1]) == 0)
			return (0);
		if (str[i] == '-')
			sign--;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	sign = ft_check_sign(sign);
	return (sign * num);
}

static int	ft_check_sign(int sign)
{
	if (sign % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (sign);
}
