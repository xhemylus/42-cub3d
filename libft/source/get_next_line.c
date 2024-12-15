/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:44:54 by vpericat          #+#    #+#             */
/*   Updated: 2022/06/03 15:12:28 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlcheck(char	*text)
{
	int	i;

	i = -1;
	if (!text)
		return (-1);
	while (text[++i])
	{
		if (text[i] == '\n')
			return (i);
	}
	return (-1);
}

static char	*gnlft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*dest;
	int		len;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i])
			dest[i] = s1[i];
	i = -1;
	while (s2[++i])
		dest[i + ft_strlen(s1)] = s2[i];
	dest[i + ft_strlen(s1)] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

static int	ft_leftover_manager(char **line, char **leftover, int fd)
{
	*line = ft_strdup(leftover[fd]);
	free(leftover[fd]);
	leftover[fd] = NULL;
	if (!(*line))
		return (0);
	return (1);
}

static char	*output(char *line, char **leftover)
{
	int		i;
	int		j;
	char	*dest;

	i = 1;
	while (line[i - 1] != '\n' && line[i])
		i++;
	j = i;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (multifree(1, line));
	dest[i] = '\0';
	while (--i >= 0)
		dest[i] = line[i];
	if ((int)ft_strlen(line) > j)
	{
		*leftover = ft_strdup(line + j);
		if (!*leftover)
			return (multifree(2, line, dest));
	}
	free(line);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*leftover[4096];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0))
		return (NULL);
	line = NULL;
	ret = BUFFER_SIZE;
	while (ft_nlcheck(line) == -1 && ret == BUFFER_SIZE)
	{
		if (leftover[fd])
			if (ft_leftover_manager(&line, leftover, fd) == 0)
				return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (ft_nlcheck(line) == -1)
			ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
			line = gnlft_strjoin(line, (const char *)buffer);
		else if (ret == 0 && !line)
			return (NULL);
		if (!line)
			return (NULL);
	}
	return (output(line, &leftover[fd]));
}
