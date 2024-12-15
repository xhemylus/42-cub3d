/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:31:43 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:39 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned const char	*source;
	size_t				i;

	if (!dest && !src && n)
		return (NULL);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = -1;
	while (++i < n)
		destination[i] = source[i];
	return (dest);
}
