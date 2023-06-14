/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:56:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/13 20:58:33 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < g_data.x_width) && (y >= 0 && y < g_data.y_height))
	{
		dst = g_data.addr + ((y * g_data.line_length) + \
		(x * (g_data.bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
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
		x = g_data.player.x + i * cos(ang);
		y = g_data.player.y + i * sin(ang);
		my_mlx_pixel_put(x, y, color);
		i++;
	}
}

void	fillmap(void)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = 0;
	i = 0;
	while (g_data.cart[i])
	{
		j = 0;
		while (g_data.cart[i][j])
		{
			if (g_data.cart[i][j] == '1')
				color = 0x878787;
			else
				color = 0x000000;
			x = 0;
			while (x < CUBE)
			{
				y = 0;
				while (y < CUBE)
				{
					my_mlx_pixel_put(j * CUBE + x, i * CUBE + y, color);
					y++;
				}
				x++;
			}
			j++;
		}
		i++;
	}
}

void	drawrays(void)
{
	int	i;

	i = 0;
	while (i < g_data.nbr_rays)
	{
		line(g_data.ray[i].dis, g_data.ray[i].angle, 0xFFFFFF);
		i++;
	}
}
