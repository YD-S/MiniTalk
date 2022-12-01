/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:50:32 by ysingh            #+#    #+#             */
/*   Updated: 2022/10/07 20:48:54 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				leng;
	char			*mal;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		leng = ft_strlen(s) - start;
	else
		leng = len;
	mal = malloc(sizeof(char) * leng + 1);
	if (!mal)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && i <= ft_strlen(s))
	{
		if (i >= start && j < len)
			mal[j++] = s[i];
		i++;
	}
	mal[j] = '\0';
	return (mal);
}
