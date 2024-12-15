/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:27:36 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 09:55:00 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	texture_handler(t_color *color, char *str)
{
	if (ft_strncmp("NO", str, 2) == 0)
	{
		color->north = texture_parse(ft_strdup(&str[3]), color);
		if (color->north == NULL)
			return (1);
	}
	else if (ft_strncmp("SO", str, 2) == 0)
	{
		color->south = texture_parse(ft_strdup(&str[3]), color);
		if (color->south == NULL)
			return (1);
	}
	else if (ft_strncmp("WE", str, 2) == 0)
	{
		color->west = texture_parse(ft_strdup(&str[3]), color);
		if (color->west == NULL)
			return (1);
	}
	else if (ft_strncmp("EA", str, 2) == 0)
	{
		color->east = texture_parse(ft_strdup(&str[3]), color);
		if (color->east == NULL)
			return (1);
	}
	return (0);
}

int	color_handler(t_color *color, char *str, t_cube *cube)
{
	if (ft_strncmp("NO", str, 2) == 0 || ft_strncmp("SO", str, 2) == 0
		|| ft_strncmp("WE", str, 2) == 0 || ft_strncmp("EA", str, 2) == 0)
	{
		if (texture_handler(color, str))
			return (parse_abort(cube, -2));
	}
	else if (ft_strncmp("F", str, 1) == 0)
	{
		color->floor = rgbtohex(str, color);
		if (color->floor == -1)
			return (parse_abort(cube, -3));
	}	
	else if (ft_strncmp("C", str, 1) == 0)
	{
		color->ceiling = rgbtohex(str, color);
		if (color->ceiling == -1)
			return (parse_abort(cube, -3));
	}
	else if (*str == '\n')
		return (0);
	else if (color->count != 6)
		return (parse_abort(cube, -1));
	return (color->count);
}

int	color_parser(t_cube *cube, int fd)
{
	int		temp;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (parse_abort(cube, my_error("malloc")));
	temp = 0;
	while (line && temp < 6)
	{
		temp = color_handler(&cube->color, line, cube);
		free(line);
		line = NULL;
		if (temp == -1)
			return (my_error("Missing Color"));
		else if (temp < -1)
			return (1);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (cube->color.count != 6)
		return (parse_abort(cube, my_error("something went wrong [read]")));
	return (0);
}

char	*texture_parse(char *path, t_color *color)
{
	int		temp;
	char	*ext;

	ext = ft_strrsearch(path, '.');
	if (!ext || ft_strcmp(ext, ".xpm\n") != 0)
	{
		ft_putstr_fd("Error: invalid texture extension\n", 2);
		return (NULL);
	}
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	temp = open(path, O_RDONLY);
	if (temp <= 0)
	{
		ft_putstr_fd("Error: failed to open texture\n", 2);
		return (NULL);
	}
	close (temp);
	color->count++;
	return (path);
}

int	map_parser(t_cube *cube, char *path)
{
	int		fd;
	char	*ext;

	cube->map.list = NULL;
	ext = ft_strrsearch(path, '.');
	if (!ext || ft_strcmp(ext, ".cub") != 0)
		return (my_error("Invalid file extension\n"));
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (my_error("Couldn't open map\n"));
	if (color_parser(cube, fd))
	{
		close(fd);
		return (1);
	}
	if (map_reader(&cube->map, fd) || map_alloc(&cube->map)
		|| map_checker(cube, &cube->map))
	{
		close (fd);
		return (parse_abort(cube, 1));
	}
	close (fd);
	return (0);
}
