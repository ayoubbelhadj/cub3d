/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:51:26 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:06 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	ft_texture_v_norm(int i)
{
	int	j;
	int	distop;
	int	y;
	int	x;

	j = 0;
	x = fmod(g_data.ray[i].y, CUBE) / CUBE * g_data.we.img_w;
	while (g_data.g3d[i].y < g_data.g3d[i].wallbottom && j < WIN_H)
	{
		distop = g_data.g3d[i].y + (g_data.g3d[i].wbwh / 2) - (WIN_H / 2);
		y = floor((distop * g_data.we.img_h) / g_data.g3d[i].wbwh);
		my_mlx_pixel_put2(i, g_data.g3d[i].y,
			*((int *)(g_data.we.addr + (y * g_data.we.img_w + x))));
		g_data.g3d[i].y++;
		j++;
	}
}

void	ft_texture_v(int i)
{
	int	distop;
	int	j;
	int	y;
	int	x;

	j = 0;
	if (g_data.ray[i].right)
	{
		x = fmod(g_data.ray[i].y, CUBE) / CUBE * g_data.ea.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom && j < WIN_H)
		{
			distop = g_data.g3d[i].y + (g_data.g3d[i].wbwh / 2) - (WIN_H / 2);
			y = floor((distop * g_data.ea.img_h) / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.ea.addr + (y * g_data.ea.img_w + x))));
			g_data.g3d[i].y++;
			j++;
		}
	}
	else
		ft_texture_v_norm(i);
}

void	ft_texture_h_norm(int i)
{
	int	j;
	int	distop;
	int	y;
	int	x;

	j = 0;
	x = fmod(g_data.ray[i].x, CUBE) / CUBE * g_data.so.img_w;
	while (g_data.g3d[i].y < g_data.g3d[i].wallbottom && j < WIN_H)
	{
		distop = g_data.g3d[i].y + (g_data.g3d[i].wbwh / 2) - (WIN_H / 2);
		y = floor((distop * g_data.so.img_h) / g_data.g3d[i].wbwh);
		my_mlx_pixel_put2(i, g_data.g3d[i].y,
			*((int *)(g_data.so.addr + (y * g_data.so.img_w + x))));
		g_data.g3d[i].y++;
		j++;
	}
}

void	ft_texture_h(int i)
{
	int	distop;
	int	j;
	int	y;
	int	x;

	j = 0;
	if (g_data.ray[i].up)
	{
		x = fmod(g_data.ray[i].x, CUBE) / CUBE * g_data.no.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom && j < WIN_H)
		{
			distop = g_data.g3d[i].y + (g_data.g3d[i].wbwh / 2) - (WIN_H / 2);
			y = floor(distop * g_data.no.img_h / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.no.addr + (y * g_data.no.img_w + x))));
			g_data.g3d[i].y++;
			j++;
		}
	}
	else
		ft_texture_h_norm(i);
}
