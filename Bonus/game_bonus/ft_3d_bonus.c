/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:57:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:50:51 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	img3d(void)
{
	int	i;

	i = 0;
	while (i < g_data.nbr_rays)
	{
		if (g_data.ray[i].v)
			ft_texture_v(i);
		else
			ft_texture_h(i);
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
				color = g_data.c.color;
			else
				color = g_data.f.color;
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
		if (g_data.g3d[i].walltop < 0)
			g_data.g3d[i].walltop = 0;
		g_data.g3d[i].wallbottom = (WIN_H / 2) + (g_data.g3d[i].wbwh / 2) - 1;
		if (g_data.g3d[i].wallbottom > WIN_H)
			g_data.g3d[i].wallbottom = WIN_H ;
		g_data.g3d[i].x = g_data.g3d[i].walltop;
		g_data.g3d[i].y = g_data.g3d[i].x + 1;
		i++;
	}
}
