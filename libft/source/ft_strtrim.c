/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:06:59 by vpericat          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:56 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	const char	*word;
	char		*dest;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_ischarset(set, s1[i]))
		i++;
	word = &s1[i];
	i = 0;
	while (word[i])
		i++;
	i = i - 1;
	while (i > 0 && ft_ischarset(set, word[i]))
		i--;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	dest[++i] = '\0';
	while (--i >= 0)
		dest[i] = word[i];
	return (dest);
}
