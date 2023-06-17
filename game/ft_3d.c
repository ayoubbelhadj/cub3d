/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:57:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 14:35:26 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_texture_v(int i, int x, int y)
{
	if (g_data.ray[i].right)
	{
		x = fmod(g_data.ray[i].y, CUBE) / CUBE * (double)g_data.ea.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom)
		{
			y = floor(((g_data.g3d[i].y - g_data.g3d[i].x)
						* g_data.ea.img_h) / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.ea.addr + (y * g_data.ea.img_w + x))));
			g_data.g3d[i].y++;
		}
	}
	else
	{
		x = fmod(g_data.ray[i].y, CUBE) / CUBE * (double)g_data.we.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom)
		{
			y = floor(((g_data.g3d[i].y - g_data.g3d[i].x)
						* g_data.we.img_h) / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.we.addr + (y * g_data.we.img_w + x))));
			g_data.g3d[i].y++;
		}
	}
}

void	ft_texture_h(int i, int x, int y)
{
	if (g_data.ray[i].up)
	{
		x = fmod(g_data.ray[i].x, CUBE) / CUBE * (double)g_data.no.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom)
		{
			y = floor(((g_data.g3d[i].y - g_data.g3d[i].x)
						* g_data.no.img_h) / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.no.addr + (y * g_data.no.img_w + x))));
			g_data.g3d[i].y++;
		}
	}
	else
	{
		x = fmod(g_data.ray[i].x, CUBE) / CUBE * (double)g_data.so.img_w;
		while (g_data.g3d[i].y < g_data.g3d[i].wallbottom)
		{
			y = floor(((g_data.g3d[i].y - g_data.g3d[i].x)
						* g_data.so.img_h) / g_data.g3d[i].wbwh);
			my_mlx_pixel_put2(i, g_data.g3d[i].y,
				*((int *)(g_data.so.addr + (y * g_data.so.img_w + x))));
			g_data.g3d[i].y++;
		}
	}
}

void	img3d(void)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	x = 0;
	y = 0;
	while (i < g_data.nbr_rays)
	{
		if (g_data.ray[i].v)
			ft_texture_v(i, x, y);
		else
			ft_texture_h(i, x, y);
		i++;
	}
}

void	rend3d(void)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			if (j < WIN_H / 2)
				color = rgb(56, 33, 23);
			else
				color = rgb(214, 189, 141);
			my_mlx_pixel_put2(i, j, color);
			j++;
		}
		i++;
	}
}

void	g3d(void)
{
	int	i;

	i = 0;
	while (i < g_data.nbr_rays)
	{
		g_data.g3d[i].disproj = (WIN_W / 2) / tan(g_data.viewangle / 2);
		vapsangle(&g_data.ray[i].angle);
		g_data.g3d[i].disprojfix = g_data.ray[i].dis
			* cos(g_data.ray[i].angle - g_data.player.alpha);
		vapsangle(&g_data.ray[i].angle);
		g_data.g3d[i].projwallh = (CUBE / g_data.g3d[i].disprojfix)
			* g_data.g3d[i].disproj;
		vapsangle(&g_data.ray[i].angle);
		g_data.g3d[i].wbwh = g_data.g3d[i].projwallh;
		g_data.g3d[i].walltop = (WIN_H / 2) - (g_data.g3d[i].wbwh / 2);
		g_data.g3d[i].wallbottom = (WIN_H / 2) + (g_data.g3d[i].wbwh / 2) - 1;
		g_data.g3d[i].x = g_data.g3d[i].walltop;
		g_data.g3d[i].y = g_data.g3d[i].x + 1;
		i++;
	}
}
