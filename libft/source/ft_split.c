/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:47:48 by vpericat          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:36 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	isword;

	i = -1;
	count = 0;
	isword = 0;
	while (s[++i])
	{
		if (isword && s[i] == c)
			isword = 0;
		else if (!isword && s[i] != c)
		{
			count++;
			isword = 1;
		}
	}
	return (count);
}

void	*ft_freeall(int curr, char **dest)
{
	int	i;

	i = -1;
	while (++i < curr)
		free(dest[i]);
	free(dest);
	return (NULL);
}

static char	**ft_dispatch(char const *s, char c, char **dest)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = -1;
			dest[++j] = malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1));
			if (!dest[j])
				return (ft_freeall(j, dest));
			while (s[i] && s[i] != c)
				dest[j][++k] = s[i++];
			dest[j][++k] = '\0';
		}
	}
	dest[j + 1] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**destarray;

	if (!s)
		return (NULL);
	destarray = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!destarray)
		return (NULL);
	destarray = ft_dispatch(s, c, destarray);
	if (!destarray)
		return (NULL);
	return (destarray);
}
