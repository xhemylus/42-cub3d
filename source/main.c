/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:19:06 by abollen           #+#    #+#             */
/*   Updated: 2022/11/24 10:21:31 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(void *info)
{
	t_cube		*cube;
	t_renderer	*renderer;

	cube = (t_cube *)info;
	renderer = &cube->renderer;
	cube_input(cube);
	ft_memcpy(renderer->canvas.addr, renderer->background.addr,
		PIXEL_H * renderer->canvas.line_length);
	raycast(cube, renderer, &cube->player);
	mlx_put_image_to_window(cube->mlx, cube->win, renderer->canvas.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc < 2)
		return (my_error("Invalid parameters"));
	cube_init(&cube);
	if (map_parser(&cube, argv[1]))
		return (1);
	cube.mlx = mlx_init();
	cube.win = mlx_new_window(cube.mlx, PIXEL_W, PIXEL_H, "cube3d");
	if (renderer_init(&cube, &cube.renderer))
		return (1);
	mlx_loop_hook(cube.mlx, update, &cube);
	mlx_hook(cube.win, 2, 1L << 0, press_hook, &cube);
	mlx_hook(cube.win, 3, 1L << 1, release_hook, &cube);
	mlx_hook(cube.win, 17, 0, cube_close, &cube);
	mlx_loop(cube.mlx);
}
