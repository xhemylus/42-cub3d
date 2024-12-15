/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:01:28 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 14:28:48 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return (&s[i]);
	while (s[--i] && i > 0)
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
	if (s[i] == (const char)c)
		return ((char *)&s[i]);
	return (0);
}
