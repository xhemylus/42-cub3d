/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:21 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:55 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!tofind[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (tofind[j] == str[i + j] && i + j < len)
		{
			if (!tofind[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
