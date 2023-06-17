/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:56:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/15 21:42:07 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fillcube(int i, int j)
{
	int	x;
	int	y;
	// int	len;

	x = 0;
	// len = WIN_H - (ft_tablen(g_data.cart) * CUBE);
	while (x < CUBE)
	{
		y = 0;
		while (y < CUBE)
		{
			if (g_data.cart[i][j] == '1')
				my_mlx_pixel_put(j * CUBE + x, i * CUBE + y, 0xA0A00000);
			y++;
		}
		x++;
	}
}

void	fillmap(void)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	while (g_data.cart[i])
	{
		j = 0;
		while (g_data.cart[i][j])
		{
			fillcube(i, j);
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
