/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:01:37 by abollen           #+#    #+#             */
/*   Updated: 2022/11/30 10:38:57 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setneighbors(t_int2d *np, int x, int y)
{
	np[0].x = x;
	np[0].y = y - 1;
	np[1].x = x - 1;
	np[1].y = y;
	np[2].x = x + 1;
	np[2].y = y;
	np[3].x = x;
	np[3].y = y + 1;
}

int	checktiles(t_map *map, t_int2d head)
{
	char	neighbors[4];
	t_int2d	np[4];
	int		i;
	int		ret;

	setneighbors(np, head.x, head.y);
	i = -1;
	while (++i < 4)
		neighbors[i] = map->buffer[np[i].y * map->width + np[i].x];
	i = -1;
	ret = 0;
	while (++i < 4)
	{
		if (neighbors[i] == '.' || np[i].x < 0 || np[i].x >= map->width
			|| np[i].y < 0 || np[i].y >= map->height)
			ret = 1;
	}
	map->buffer[head.y * map->width + head.x] = 'x';
	return (ret);
}

int	checkwalls(t_map *map)
{
	int		ret[2];
	t_list	*tiles;
	t_int2d	head;

	tiles = NULL;
	head.y = -1;
	ft_bzero(ret, 2 * sizeof(int));
	while (++head.y < map->height)
	{
		head.x = -1;
		while (++head.x < map->width)
		{
			if (map->buffer[head.y * map->width + head.x] == '0')
				ret[0] = checktiles(map, head);
			if (ret[0] == 1)
					ret[1] = 1;
		}
	}
	head.y = -1;
	while (++head.y < map->height * map->width)
		if (map->buffer[head.y] == '0')
			map->buffer[head.y] = 0;
	return (ret[1]);
}
