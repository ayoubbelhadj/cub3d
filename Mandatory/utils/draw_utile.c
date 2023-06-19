/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:23:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 20:36:16 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < MSIZE) && (y >= 0 && y < MSIZE))
	{
		dst = g_data.img.addr + ((y * g_data.img.line_length) + \
		(x * (g_data.img.bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put2(int x, int y, int color)
{
	char	*dst2;

	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		dst2 = g_data.img2.addr + ((y * g_data.img2.line_length) + \
		(x * (g_data.img2.bits_per_pixel / 8)));
		*(unsigned int *)dst2 = color;
	}
}

int	rgb(int r, int g, int b)
{
	int	rgb;

	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}

void	drawcircle(int xc, int yc, int radius)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(xc + x, yc + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	line(double dis, double ang, int color)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < dis)
	{
		x = (MSIZE / 2) + i * cos(ang);
		y = (MSIZE / 2) + i * sin(ang);
		if ((x >= 0 && x < MSIZE) && (y >= 0 && y < MSIZE))
			my_mlx_pixel_put(x, y, color);
		i++;
	}
}
