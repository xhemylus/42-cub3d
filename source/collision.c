/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:38:27 by abollen           #+#    #+#             */
/*   Updated: 2022/11/22 09:41:45 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	collision_horizontal(t_cube *cube, t_player *player, t_float2d vel)
{
	t_ray		ray;

	if (vel.x < 0.001f)
	{
		ray_calc(&ray, cube, PI);
		if (ray.distance >= 20.0f)
			player->pos.x += vel.x;
	}
	else if (vel.x > -0.001f)
	{
		ray_calc(&ray, cube, 0.00f);
		if (ray.distance >= 20.0f)
			player->pos.x += vel.x;
	}
}

void	collision_vertical(t_cube *cube, t_player *player, t_float2d vel)
{
	t_ray		ray;

	if (vel.y < -0.001f)
	{
		ray_calc(&ray, cube, PI * 1.5f);
		if (ray.distance >= 20.0f)
			player->pos.y += vel.y;
	}
	else if (vel.y > 0.001f)
	{
		ray_calc(&ray, cube, PI * 0.5f);
		if (ray.distance >= 20.0f)
			player->pos.y += vel.y;
	}
}
