/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:50:26 by vpericat          #+#    #+#             */
/*   Updated: 2022/03/10 14:39:17 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char sep)
{
	int		i;
	int		needsep;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	needsep = sep != 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 + needsep));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	if (needsep)
		dest[i] = sep;
	i = -1;
	while (s2[++i])
		dest[i + ft_strlen(s1) + needsep] = s2[i];
	dest[i + ft_strlen(s1) + needsep] = '\0';
	return (dest);
}
