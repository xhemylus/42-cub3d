/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:43:09 by vpericat          #+#    #+#             */
/*   Updated: 2022/12/02 10:40:59 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_ray *ray)
{
	ray->angle = 0.0f;
	ray->pos.x = 0.0f;
	ray->pos.y = 0.0f;
	ray->xoffset = 0.0f;
	ray->yoffset = 0.0f;
	ray->distance = 0.0f;
	ray->atan = 0.0f;
	ray->dof = 0;
	ray->dir = 0x00000000;
}

void	mapi(t_map *map, t_player *player, t_ray *ray)
{
	int	mapi;

	while (ray->dof < 64)
	{
		mapi = ((int)ray->pos.y >> 6) * map->width
			+ ((int)ray->pos.x >> 6);
		if (mapi > 0 && mapi < map->height
			* map->width && map->buffer[mapi] == '1')
		{
			ray->dof = 64;
		}
		else
		{
			ray->pos.x += ray->xoffset;
			ray->pos.y += ray->yoffset;
			ray->dof += 1;
		}
	}
	ray->distance = distance(player->pos.x, player->pos.y,
			ray->pos.x, ray->pos.y);
}

void	ray_hit_horizontal(t_map *map, t_player *player, t_ray *ray)
{
	ray->dof = 0;
	ray->atan = -1.0f / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->dir = 1;
		ray->pos.y = (((int)player->pos.y >> 6) << 6) - 0.001f;
		ray->pos.x = (player->pos.y - ray->pos.y) * ray->atan + player->pos.x;
		ray->yoffset = -64;
		ray->xoffset = -ray->yoffset * ray->atan;
	}
	if (ray->angle < PI)
	{
		ray->dir = 0;
		ray->pos.y = (((int)player->pos.y >> 6) << 6) + 64;
		ray->pos.x = (player->pos.y - ray->pos.y) * ray->atan + player->pos.x;
		ray->yoffset = 64;
		ray->xoffset = -ray->yoffset * ray->atan;
	}
	if (ray->angle == 0.0f || ray->angle == PI)
	{
		ray->pos.x = 340282346638528859811704183484516925440.00f;
		ray->pos.y = player->pos.y;
		ray->dof = 64;
	}
	mapi(map, player, ray);
}

void	ray_hit_vertical(t_map *map, t_player *player, t_ray *ray)
{
	ray->atan = -tan(ray->angle);
	if (ray->angle > 0.5f * PI && ray->angle < 3 * 0.5f * PI)
	{
		ray->dir = 3;
		ray->pos.x = (((int)player->pos.x >> 6) << 6) - 0.001f;
		ray->pos.y = (player->pos.x - ray->pos.x) * ray->atan + player->pos.y;
		ray->xoffset = -64;
		ray->yoffset = -ray->xoffset * ray->atan;
	}
	if (ray->angle < 0.5f * PI || ray->angle > 3 * 0.5f * PI)
	{
		ray->dir = 2;
		ray->pos.x = (((int)player->pos.x >> 6) << 6) + 64;
		ray->pos.y = (player->pos.x - ray->pos.x) * ray->atan + player->pos.y;
		ray->xoffset = 64;
		ray->yoffset = -ray->xoffset * ray->atan;
	}
	if (ray->angle == 0.5f * PI || ray->angle == 1.5f * PI)
	{
		ray->pos.x = player->pos.x;
		ray->pos.y = 340282346638528859811704183484516925440.00f;
		ray->dof = 8;
	}
	mapi(map, player, ray);
}
