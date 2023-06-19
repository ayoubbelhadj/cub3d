/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vcast_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:00:58 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:08 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	vbreak(int i)
{
	g_data.ray[i].iswallv = 1;
	g_data.ray[i].vwallx = g_data.ray[i].vxnext;
	g_data.ray[i].vwally = g_data.ray[i].vynext;
}

void	vcal(int i)
{
	g_data.ray[i].vxnext = 0;
	g_data.ray[i].vynext = 0;
	g_data.ray[i].vx = floor(g_data.player.x / CUBE) * (double)CUBE;
	if (isright(g_data.ray[i].angle))
		g_data.ray[i].vx += CUBE;
	g_data.ray[i].vy = g_data.player.y
		+ ((g_data.ray[i].vx - g_data.player.x) * tan(g_data.ray[i].angle));
	g_data.ray[i].vxstep = CUBE;
	if ((!isright(g_data.ray[i].angle) && g_data.ray[i].vxstep > 0))
		g_data.ray[i].vxstep *= -1;
	g_data.ray[i].vystep = CUBE * tan(g_data.ray[i].angle);
	if ((!isdown(g_data.ray[i].angle) && g_data.ray[i].vystep > 0)
		|| (isdown(g_data.ray[i].angle) && g_data.ray[i].vystep < 0))
		g_data.ray[i].vystep *= -1;
	g_data.ray[i].vxnext = g_data.ray[i].vx;
	g_data.ray[i].vynext = g_data.ray[i].vy;
}

void	v_cast(int i)
{
	vcal(i);
	while (g_data.ray[i].vxnext >= 0 && g_data.ray[i].vxnext < g_data.x_width
		&& g_data.ray[i].vynext >= 0 && g_data.ray[i].vynext < g_data.y_height)
	{
		if (!isright(g_data.ray[i].angle))
		{
			if (is_wall(g_data.ray[i].vxnext - 1, g_data.ray[i].vynext))
			{
				vbreak(i);
				break ;
			}
		}
		if (is_wall(g_data.ray[i].vxnext, g_data.ray[i].vynext))
		{
			vbreak(i);
			break ;
		}
		g_data.ray[i].vxnext += g_data.ray[i].vxstep;
		g_data.ray[i].vynext += g_data.ray[i].vystep;
	}
}
