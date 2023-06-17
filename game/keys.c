/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 00:45:23 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keys(int key, t_data *data)
{
	if (key == 123)
		turn_right(0);
	if (key == 124)
		turn_left(0);
	if (key == 1 || key == 125)
		move_down(data);
	if (key == 13 || key == 126)
		move_top(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		quit(data);
	//update();
	return (0);
}

int	mouse(int x)
{
	if (x > 0 && x < 2 * WIN_W / 5)
		g_data.player.dirturn = -1;
	else if (x < WIN_W && x > WIN_W - (2 * WIN_W / 5))
		g_data.player.dirturn = 1;
	else
		g_data.player.dirturn = 0;
	// if (((g_data.xmouse - x) >= -5 && (g_data.xmouse - x) <= 5))
	// 	g_data.player.dirturn = 0;
	// else if (x > (g_data.xmouse))
	// 	g_data.player.dirturn = 1;
	// else
	// 	g_data.player.dirturn = -1;
	g_data.xmouse = x;
	return (0);
}
