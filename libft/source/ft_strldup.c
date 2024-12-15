/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:44:01 by vpericat          #+#    #+#             */
/*   Updated: 2022/04/08 18:44:56 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *src, size_t size)
{
	unsigned int	i;
	char			*dest;

	i = -1;
	if (ft_strlen(src) < size)
		dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	else
		dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	while (src[++i] && i < size)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
