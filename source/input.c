/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:20:19 by abollen           #+#    #+#             */
/*   Updated: 2022/11/25 12:29:11 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cube_close(void *info)
{
	t_cube		*cube;
	t_renderer	*renderer;

	cube = (t_cube *)info;
	renderer = &cube->renderer;
	mlx_destroy_image(cube->mlx, renderer->canvas.img);
	mlx_destroy_image(cube->mlx, renderer->background.img);
	mlx_destroy_image(cube->mlx, renderer->north.img);
	mlx_destroy_image(cube->mlx, renderer->south.img);
	mlx_destroy_image(cube->mlx, renderer->west.img);
	mlx_destroy_image(cube->mlx, renderer->east.img);
	mlx_destroy_window(cube->mlx, cube->win);
	free(cube->map.buffer);
	exit(0);
	return (0);
}

void	cube_input(t_cube *cube)
{
	t_player	*player;
	t_float2d	temp;
	t_float2d	vel;

	player = &cube->player;
	player->angle += cube->input.r * player->r_speed;
	if (player->angle > PI * 2.0f)
		player->angle -= 2.0f * PI;
	else if (player->angle < 0.0f)
		player->angle += 2.0f * PI;
	temp.x = cos(player->angle) * player->speed;
	temp.y = sin(player->angle) * player->speed;
	vel.x = (float)cube->input.y * temp.x + (-temp.y) * (float)cube->input.x;
	vel.y = (float)cube->input.y * temp.y + temp.x * (float)cube->input.x;
	collision_vertical(cube, player, vel);
	collision_horizontal(cube, player, vel);
}

int	press_hook(int keycode, t_cube *cube)
{
	if (keycode == KEY_W)
		cube->input.y = 1;
	else if (keycode == KEY_A)
		cube->input.x = -1;
	else if (keycode == KEY_S)
		cube->input.y = -1;
	else if (keycode == KEY_D)
		cube->input.x = 1;
	else if (keycode == KEY_LEFT)
		cube->input.r = -1;
	else if (keycode == KEY_RIGHT)
		cube->input.r = 1;
	else if (keycode == 53)
		cube_close(cube);
	else if (keycode == 48)
		cube->input.tab = 1;
	return (0);
}

int	release_hook(int keycode, t_cube *cube)
{
	if (keycode == KEY_W)
		cube->input.y = 0;
	else if (keycode == KEY_A)
		cube->input.x = 0;
	else if (keycode == KEY_S)
		cube->input.y = 0;
	else if (keycode == KEY_D)
		cube->input.x = 0;
	else if (keycode == KEY_LEFT)
		cube->input.r = 0;
	else if (keycode == KEY_RIGHT)
		cube->input.r = 0;
	else if (keycode == 53)
		cube_close(cube);
	else if (keycode == 48)
		cube->input.tab = 0;
	return (0);
}

void	cube_init(t_cube *cube)
{
	cube->input.x = 0;
	cube->input.y = 0;
	cube->input.r = 0;
	cube->input.tab = 0;
	cube->player.speed = 3.0f;
	cube->player.r_speed = 0.02f;
	cube->color.count = 0;
	cube->color.north = NULL;
	cube->color.south = NULL;
	cube->color.west = NULL;
	cube->color.east = NULL;
}
