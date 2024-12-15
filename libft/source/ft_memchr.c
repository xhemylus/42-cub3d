/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:58:29 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:37 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	i = -1;
	source = (unsigned char *)src;
	while (++i < n)
		if (source[i] == (unsigned char)c)
			return (&source[i]);
	return (NULL);
}
