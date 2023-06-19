/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:56:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 21:29:54 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	check_elem(double x, double y)
{
	if (x < 0 || x >= g_data.x_width || y < 0 || y >= g_data.y_height)
		return ('2');
	x = floor(x / CUBE);
	y = floor(y / CUBE);
	return (g_data.cart[(int)y][(int)x]);
}

void	fillmap(void)
{
	double		x_start;
	double		y_start;
	int			x;
	int			y;

	x_start = g_data.player.x - (MSIZE / 2);
	y_start = g_data.player.y - (MSIZE / 2);
	x = 0;
	while (x < MSIZE)
	{
		y = 0;
		while (y < MSIZE)
		{
			if (check_elem(x_start + x, y_start + y) == '1')
				my_mlx_pixel_put(x, y, 0x000000);
			else if (check_elem(x_start + x, y_start + y) == '0'
				|| check_elem(x_start + x, y_start + y) == g_data.pars.pos)
				my_mlx_pixel_put(x, y, g_data.f.color);
			else
				my_mlx_pixel_put(x, y, g_data.c.color);
			y++;
		}
		x++;
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
