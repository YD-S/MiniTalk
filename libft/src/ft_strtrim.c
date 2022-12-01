/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:45:55 by ysingh            #+#    #+#             */
/*   Updated: 2022/10/07 11:08:56 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	frontend;
	size_t	backend;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	str = 0;
	if (s1 != 0 && set != 0)
	{
		frontend = 0;
		backend = ft_strlen(s1);
		while (s1[frontend] && ft_strchr(set, s1[frontend]))
			frontend++;
		while (s1[backend - 1] && ft_strchr(set, s1[backend - 1])
			&& backend > frontend)
			backend--;
		str = (char *)malloc(sizeof(char) * (backend - frontend + 1));
		if (str)
			ft_strlcpy(str, &s1[frontend], backend - frontend + 1);
	}
	return (str);
}
