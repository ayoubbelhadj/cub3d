/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:12:29 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:07 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	vapsangle(double *angle)
{
	*angle = fmod(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle += 2 * M_PI;
}

void	turn_left(int flag)
{
	g_data.player.dirturn = 1;
	if (flag)
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate_m;
	else
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate;
	vapsangle(&g_data.player.alpha);
}

void	turn_right(int flag)
{
	g_data.player.dirturn = -1;
	if (flag)
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate_m;
	else
		g_data.player.alpha += g_data.player.dirturn
			* g_data.player.speedretate;
	vapsangle(&g_data.player.alpha);
}
