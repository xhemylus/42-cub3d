/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:03:43 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 12:06:48 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_abort(t_cube *cube)
{
	if (cube->color.north)
		free(cube->color.north);
	if (cube->color.south)
		free(cube->color.south);
	if (cube->color.west)
		free(cube->color.west);
	if (cube->color.east)
		free(cube->color.east);
	if (cube->renderer.north.img != NULL)
		mlx_destroy_image(cube->mlx, cube->renderer.north.img);
	if (cube->renderer.south.img != NULL)
		mlx_destroy_image(cube->mlx, cube->renderer.south.img);
	if (cube->renderer.west.img != NULL)
		mlx_destroy_image(cube->mlx, cube->renderer.west.img);
	if (cube->renderer.east.img != NULL)
		mlx_destroy_image(cube->mlx, cube->renderer.east.img);
	if (cube->map.list)
		ft_lstclear(&cube->map.list, free);
	free(cube->map.buffer);
	cube->map.buffer = NULL;
	mlx_destroy_window(cube->mlx, cube->win);
	exit(1);
	return (1);
}

int	texture_init(t_data *data, t_cube *cube, char **path)
{
	if (path == NULL)
		return (1);
	data->img = mlx_xpm_file_to_image(cube->mlx, *path,
			&data->width, &data->height);
	free(*path);
	*path = NULL;
	if (data->img == NULL)
		return (my_error("invalid texture"));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}

void	image_init(t_data *data, t_cube *cube, int width, int height)
{
	data->img = mlx_new_image(cube->mlx, width, height);
	data->width = width;
	data->height = height;
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	offset_init(t_renderer *renderer)
{
	double	offset;
	double	step;
	double	temp;
	int		i;

	i = -1;
	temp = 1.00 / cos(renderer->fov / 2.00);
	temp = sqrt(temp * temp - 1.00);
	offset = -temp;
	step = temp / (double)(PIXEL_W / 2.00);
	while (++i < PIXEL_W)
	{
		temp = offset + step * ((double)i);
		renderer->rayoffset[i] = asin(temp / sqrt(temp * temp + 1.00));
		renderer->dangle[i] = cos(fwrap(renderer->rayoffset[i], 0.0f, TAU));
	}
}

int	renderer_init(t_cube *cube, t_renderer *renderer)
{
	renderer->north.img = NULL;
	renderer->south.img = NULL;
	renderer->west.img = NULL;
	renderer->east.img = NULL;
	if (texture_init(&renderer->north, cube, &cube->color.north))
		return (texture_abort(cube));
	if (texture_init(&renderer->south, cube, &cube->color.south))
		return (texture_abort(cube));
	if (texture_init(&renderer->west, cube, &cube->color.west))
		return (texture_abort(cube));
	if (texture_init(&renderer->east, cube, &cube->color.east))
		return (texture_abort(cube));
	image_init(&renderer->canvas, cube, PIXEL_W, PIXEL_H);
	image_init(&renderer->background, cube, PIXEL_W, PIXEL_H);
	drawzone(&renderer->background, 0, PIXEL_H / 2, cube->color.ceiling);
	drawzone(&renderer->background, PIXEL_H / 2,
		PIXEL_H, cube->color.floor);
	renderer->fov = FOV * DEG2RAD;
	offset_init(renderer);
	return (0);
}
