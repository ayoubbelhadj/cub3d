/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 14:05:23 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	return (0);
}
