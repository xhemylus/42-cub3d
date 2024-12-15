/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpericat <vpericat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:26:19 by abollen           #+#    #+#             */
/*   Updated: 2022/12/02 12:06:58 by vpericat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	puttexpix(t_data *data, t_data *tex, t_int2d pos, t_int2d uv)
{
	char	*dst;

	if (uv.x < tex->width && uv.x >= 0 && uv.y < tex->height && uv.y >= 0)
	{
		dst = tex->addr + uv.x * (unsigned int)(tex->bits_per_pixel >> 3)
			+ uv.y * tex->line_length;
		if (((*(unsigned int *)dst) >> 24) < 254)
			putpixel(data, pos.x, pos.y, *(unsigned int *)dst);
	}
}

void	putpixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->width && x >= 0 && y < data->height && y >= 0)
	{
		if (x < PIXEL_W && y < PIXEL_H)
		{
			dst = data->addr + (y * data->line_length + x
					* (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	drawzone(t_data *img, int start, int end, int color)
{
	int	y;
	int	x;

	y = start - 1;
	while (++y < end)
	{
		x = -1;
		while (++x < PIXEL_W)
			putpixel(img, x, y, color);
	}
}
