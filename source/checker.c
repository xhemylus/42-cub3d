/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:09:12 by abollen           #+#    #+#             */
/*   Updated: 2022/11/24 10:11:41 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	player_checker(t_cube *cube, t_map *map)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (map->buffer[i])
	{
		if (map->buffer[i] == 'N' || map->buffer[i] == 'S'
			|| map->buffer[i] == 'E' || map->buffer[i] == 'W')
		{
			player_setup(cube, map, i);
			map->buffer[i] = '0';
			player++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	map_checker(t_cube *cube, t_map *map)
{
	if (player_checker(cube, map))
	{
		free(cube->map.buffer);
		return (my_error("player"));
	}
	if (checkwalls(map))
	{
		free(cube->map.buffer);
		return (my_error("map isn't closed"));
	}
	return (0);
}
