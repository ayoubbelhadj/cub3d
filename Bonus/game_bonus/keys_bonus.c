/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:02 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

int	key_off(int key)
{
	if (key == 123)
		g_data.player.dirturn = 0;
	if (key == 124)
		g_data.player.dirturn = 0;
	if (key == 1 || key == 125)
		g_data.player.dirwalk = 0;
	if (key == 13 || key == 126)
		g_data.player.dirwalk = 0;
	if (key == 0)
		g_data.player.dirwalkx = 0;
	if (key == 2)
		g_data.player.dirwalkx = 0;
	return (0);
}

int	key_on(int key)
{
	if (key == 123)
		g_data.player.dirturn = -1;
	if (key == 124)
		g_data.player.dirturn = 1;
	if (key == 1 || key == 125)
		g_data.player.dirwalk = -1;
	if (key == 13 || key == 126)
		g_data.player.dirwalk = 1;
	if (key == 0)
		g_data.player.dirwalkx = 1;
	if (key == 2)
		g_data.player.dirwalkx = -1;
	if (key == 53)
		quit(&g_data);
	if (key == 49)
		g_data.shotf = 1;
	return (0);
}

int	mouse(int x)
{
	if (g_data.pressmouse)
	{
		if (x > g_data.xmouse)
			g_data.player.dirturn = 1;
		else if (x < g_data.xmouse)
			g_data.player.dirturn = -1;
		g_data.xmouse = x;
	}
	return (0);
}

int	mouse_on(int key, int x)
{
	if (key == 2 && x >= 0 && x <= WIN_W)
	{
		g_data.xmouse = x;
		g_data.pressmouse = 1;
	}
	if (key == 1)
		g_data.shotf = 1;
	return (0);
}

int	mouse_off(int key)
{
	if (key == 2)
	{
		g_data.pressmouse = 0;
		g_data.player.dirturn = 0;
	}
	return (0);
}
