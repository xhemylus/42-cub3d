/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:01:07 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 11:41:53 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgbtohex(char *str, t_color *color)
{
	int	i;
	int	count;
	int	rgb;
	int	temp;

	i = 2;
	count = -1;
	rgb = 0;
	while (++count < 3)
	{
		rgb = rgb << 8;
		temp = ft_atoi(&str[i]);
		if (temp > 255 || temp < 0)
			return (-my_error("invalid color"));
		rgb += temp;
		while (str[i] != ',' && str[i])
			i++;
		i++;
	}
	color->count++;
	return (rgb);
}

int	map_reader(t_map *map, int fd)
{
	char	*temp;

	map->width = 0;
	map->height = 0;
	temp = get_next_line(fd);
	if (temp == NULL)
		return (my_error("malloc"));
	map->width = ft_strlen(temp) - 1;
	map->height++;
	map->list = ft_lstnew((void *)temp);
	while (temp != NULL && temp[ft_strlen(temp) - 1] == '\n')
	{
		temp = get_next_line(fd);
		if ((int)ft_strlen(temp) - 1 > map->width)
			map->width = ft_strlen(temp) - 1;
		if (temp)
		{
			ft_lstadd_back(&map->list, ft_lstnew((void *)temp));
			map->height++;
		}
	}
	return (0);
}

int	map_alloc(t_map *map)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	map->buffer = malloc((map->height * (map->width)) + 1);
	if (!map->buffer)
		return (my_error("malloc"));
	while (map->list != NULL)
	{
		str = (char *)map->list->content;
		i = -1;
		while (++i < map->width)
		{
			if (i < (int)ft_strlen(str) && str[i] != ' ' && str[i] != '\n')
				map->buffer[j] = str[i];
			else
				map->buffer[j] = ' ';
			j++;
		}
		ft_lstdelfirst(&map->list, free);
	}
	map->buffer[j] = '\0';
	map->list = NULL;
	return (0);
}

void	player_setup(t_cube *cube, t_map *map, int index)
{
	cube->player.pos.y = index / map->width * 64 + 32;
	cube->player.pos.x = index % map->width * 64 + 32;
	if (map->buffer[index] == 'N')
		cube->player.angle = 270.0f * DEG2RAD;
	else if (map->buffer[index] == 'S')
	{
		cube->player.angle = 90.0f * DEG2RAD;
	}
	else if (map->buffer[index] == 'W')
		cube->player.angle = 180.0f * DEG2RAD;
	else if (map->buffer[index] == 'E')
		cube->player.angle = 0.0f;
}

int	parse_abort(t_cube *cube, int ret)
{
	if (cube->color.north)
		free(cube->color.north);
	if (cube->color.south)
		free(cube->color.south);
	if (cube->color.west)
		free(cube->color.west);
	if (cube->color.east)
		free(cube->color.east);
	cube->color.north = NULL;
	cube->color.south = NULL;
	cube->color.west = NULL;
	cube->color.east = NULL;
	if (cube->map.list)
		ft_lstclear(&cube->map.list, free);
	return (ret);
}
