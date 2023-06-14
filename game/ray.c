/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:02:12 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/13 21:07:40 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	distance(double x, double y)
{
	double	dis;

	dis = sqrt((x - g_data.player.x) * (x - g_data.player.x)
			+ (y - g_data.player.y) * (y - g_data.player.y));
	return (dis);
}

void	checkdis(int i)
{
	double	hdis;
	double	vdis;

	if (g_data.ray[i].iswallh)
		hdis = distance(g_data.ray[i].hwallx, g_data.ray[i].hwally);
	else
		hdis = LONG_MAX;
	if (g_data.ray[i].iswallv)
		vdis = distance(g_data.ray[i].vwallx, g_data.ray[i].vwally);
	else
		vdis = LONG_MAX;
	if (vdis >= hdis)
		g_data.ray[i].dis = hdis;
	else
		g_data.ray[i].dis = vdis;
}

void	sendrays(void)
{
	int		i;
	double	rayangle;

	i = 0;
	rayangle = g_data.player.alpha - (g_data.viewangle / 2);
	while (i < g_data.nbr_rays)
	{
		g_data.ray[i].iswallh = 0;
		g_data.ray[i].iswallv = 0;
		vapsangle(&rayangle);
		g_data.ray[i].angle = rayangle;
		h_cast(i);
		v_cast(i);
		checkdis(i);
		rayangle += g_data.viewangle / g_data.nbr_rays;
		vapsangle(&rayangle);
		i++;
	}
}
