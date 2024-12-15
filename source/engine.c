/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:42:39 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 11:12:45 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawray(t_data *canvas, int start, int height, t_ray *ray)
{
	int		x;
	int		y;
	t_int2d	px;
	int		offset;

	x = -1;
	offset = (PIXEL_H >> 1) - (height >> 1);
	while (++x < 1)
	{
		y = -1;
		if (offset < 0.0f)
			y = - (offset) - 1;
		while (++y < height && offset + y < PIXEL_H - 1)
		{
			ray->uv.y = (((y << 10) / height) * ray->texture->height) >> 10;
			px.x = start + x;
			px.y = offset + y;
			puttexpix(canvas, ray->texture, px, ray->uv);
		}
	}
}

void	ray_calc(t_ray *ray, t_cube *cube, float rayangle)
{
	static int	prev = 1;
	t_ray		rays[2];
	int			shortest;

	ray_init(&rays[0]);
	ray_init(&rays[1]);
	rays[0].angle = rayangle;
	rays[1].angle = rayangle;
	ray_hit_vertical(&cube->map, &cube->player, &rays[0]);
	ray_hit_horizontal(&cube->map, &cube->player, &rays[1]);
	shortest = 0;
	if (rays[1].distance < rays[0].distance)
		shortest = 1;
	if (fabs(rays[0].distance - rays[1].distance) <= 0.01f)
		shortest = prev;
	*ray = rays[shortest];
	prev = shortest;
}

void	getu(t_ray *ray, t_renderer *renderer)
{
	int	axis;

	if (ray->dir == 0 || ray->dir == 1)
		axis = (int)fabs(ray->pos.x * 16.0f) % 1024;
	else if (ray->dir == 2 || ray->dir == 3)
		axis = (int)fabs(ray->pos.y * 16.0f) % 1024;
	if (ray->dir == 1 || ray->dir == 2)
	{
		if (ray->dir == 1)
			ray->texture = &renderer->north;
		else if (ray->dir == 2)
			ray->texture = &renderer->west;
		ray->uv.x = ((axis * (ray->texture->width - 1)) >> 10);
	}
	else if (ray->dir == 0 || ray->dir == 3)
	{
		if (ray->dir == 0)
			ray->texture = &renderer->south;
		else if (ray->dir == 3)
			ray->texture = &renderer->east;
		ray->uv.x = (((1024 - (axis)) * (ray->texture->width - 1)) >> 10);
	}
}

void	raycast(t_cube *cube, t_renderer *renderer, t_player *player)
{
	int		i;
	t_ray	ray;
	double	rayangle;
	double	distance;

	i = -1;
	while (++i < PIXEL_W)
	{
		rayangle = fwrap(renderer->rayoffset[i] + player->angle, 0.0, TAU);
		ray_calc(&ray, cube, rayangle);
		getu(&ray, renderer);
		distance = (renderer->canvas.height) / ((ray.distance / 64.0)
				* renderer->dangle[i]);
		drawray(&renderer->canvas, i, distance, &ray);
	}
}
