/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:22:03 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:40 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*destination;
	const unsigned char		*source;

	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	if (destination < source)
	{
		while (n--)
		{
			(destination[i] = source[i]);
			i++;
		}
	}
	else
	{
		while (n--)
			(destination[n - i] = source[n - i]);
	}
	return (dst);
}
