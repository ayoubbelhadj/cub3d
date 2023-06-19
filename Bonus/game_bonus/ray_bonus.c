/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:02:12 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:05 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

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
		h_return(i, hdis);
	else
		v_return(i, vdis);
}

void	direct(int i)
{
	g_data.ray[i].down = 0;
	g_data.ray[i].up = 0;
	g_data.ray[i].left = 0;
	g_data.ray[i].right = 0;
	if (isdown(g_data.ray[i].angle))
		g_data.ray[i].down = 1;
	else
		g_data.ray[i].up = 1;
	if (isright(g_data.ray[i].angle))
		g_data.ray[i].right = 1;
	else
		g_data.ray[i].left = 1;
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
		direct(i);
		checkdis(i);
		rayangle += g_data.viewangle / g_data.nbr_rays;
		vapsangle(&rayangle);
		i++;
	}
}
