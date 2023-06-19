/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:15:55 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:50:58 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

double	distance(double x, double y)
{
	double	dis;

	dis = sqrt((x - g_data.player.x) * (x - g_data.player.x)
			+ (y - g_data.player.y) * (y - g_data.player.y));
	return (dis);
}

void	h_return(int i, double dis)
{
	g_data.ray[i].dis = dis;
	g_data.ray[i].h = 1;
	g_data.ray[i].v = 0;
	g_data.ray[i].x = g_data.ray[i].hwallx;
	g_data.ray[i].y = g_data.ray[i].hwally;
}

void	v_return(int i, double dis)
{
	g_data.ray[i].dis = dis;
	g_data.ray[i].h = 0;
	g_data.ray[i].v = 1;
	g_data.ray[i].x = g_data.ray[i].vwallx;
	g_data.ray[i].y = g_data.ray[i].vwally;
}
