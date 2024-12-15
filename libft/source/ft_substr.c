/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:53:18 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 15:12:11 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		allocsize;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		allocsize = ft_strlen(s) - start;
	else
		allocsize = len;
	dest = malloc(sizeof(char) * (allocsize + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s + start, allocsize);
	dest[allocsize] = 0;
	return (dest);
}
