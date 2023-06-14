/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hcast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:59:00 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/13 21:10:09 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hbreak(int i)
{
	g_data.ray[i].iswallh = 1;
	g_data.ray[i].hwallx = g_data.ray[i].hxnext;
	g_data.ray[i].hwally = g_data.ray[i].hynext;
}

void	hcal(int i)
{
	g_data.ray[i].hxnext = 0;
	g_data.ray[i].hynext = 0;
	g_data.ray[i].hy = floor(g_data.player.y / CUBE) * CUBE;
	if (isdown(g_data.ray[i].angle))
		g_data.ray[i].hy += CUBE;
	g_data.ray[i].hx = g_data.player.x
		+ (g_data.ray[i].hy - g_data.player.y) / tan(g_data.ray[i].angle);
	g_data.ray[i].hystep = CUBE;
	if ((!isdown(g_data.ray[i].angle) && g_data.ray[i].hystep > 0)
		|| (isdown(g_data.ray[i].angle) && g_data.ray[i].hystep < 0))
		g_data.ray[i].hystep *= -1;
	g_data.ray[i].hxstep = CUBE / tan(g_data.ray[i].angle);
	if (!isright(g_data.ray[i].angle) && g_data.ray[i].hxstep > 0)
		g_data.ray[i].hxstep *= -1;
	if (isright(g_data.ray[i].angle) && g_data.ray[i].hxstep < 0)
		g_data.ray[i].hxstep *= -1;
	g_data.ray[i].hxnext = g_data.ray[i].hx;
	g_data.ray[i].hynext = g_data.ray[i].hy;
}

void	h_cast(int i)
{
	hcal(i);
	while (g_data.ray[i].hxnext >= 0 && g_data.ray[i].hxnext < g_data.x_width
		&& g_data.ray[i].hynext >= 0 && g_data.ray[i].hynext < g_data.y_height)
	{
		if (!isdown(g_data.ray[i].angle))
		{
			if (is_wall(g_data.ray[i].hxnext, g_data.ray[i].hynext - 1))
			{
				hbreak(i);
				break ;
			}
		}
		if (is_wall(g_data.ray[i].hxnext, g_data.ray[i].hynext))
		{
			hbreak(i);
			break ;
		}
		g_data.ray[i].hxnext += g_data.ray[i].hxstep;
		g_data.ray[i].hynext += g_data.ray[i].hystep;
	}
}
