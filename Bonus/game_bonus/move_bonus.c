/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:31:10 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:02 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	walkupdown(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalk * g_data.player.speedmove;
	x = g_data.player.x + cos(g_data.player.alpha) * movespeed;
	y = g_data.player.y + sin(g_data.player.alpha) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkleftright(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalkx * g_data.player.speedmove;
	y = g_data.player.y + sin(g_data.player.alpha - M_PI_2) * movespeed;
	x = g_data.player.x + cos(g_data.player.alpha - M_PI_2) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkx(void)
{
	double	movespeed;
	double	angle;
	double	x;
	double	y;

	movespeed = g_data.player.speedmove;
	if (g_data.player.dirwalk == -1)
		angle = g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 2);
	else
		angle = g_data.player.dirwalk
			* (g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 4));
	y = g_data.player.y + sin(angle) * movespeed;
	x = g_data.player.x + cos(angle) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	move(void)
{
	g_data.player.alpha += g_data.player.dirturn
		* g_data.player.speedretate;
	if (g_data.player.dirwalk != 0 && g_data.player.dirwalkx != 0)
		walkx();
	else if (g_data.player.dirwalk != 0)
		walkupdown();
	else if (g_data.player.dirwalkx != 0)
		walkleftright();
}
