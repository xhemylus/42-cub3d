/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:01:21 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 11:16:04 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	buffer[100001];

	ft_bzero(buffer, 100001);
	i = 0;
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
		return (NULL);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

char	*ft_strrsearch(const char *string, char searchedChar)
{
	int	i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == searchedChar)
			return ((char *)&string[i]);
		i--;
	}
	return (0);
}

int	ft_isbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long	anum;
	int		i;

	anum = 0;
	i = 3;
	while (ft_isbase(str[i], base) >= 0)
	{
		anum = anum * 16;
		anum = anum + ft_isbase(str[i], base);
		i++;
	}
	return (anum);
}
