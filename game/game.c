/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:18:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/16 20:07:27 by abelhadj         ###   ########.fr       */
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
	if (key == 49)
		g_data.shotf = 1;
	return (0);
}

void	game(void)
{
	init();
	mlx_hook(g_data.mlx_win, 2, 1L << 0, key_on, NULL);
	mlx_hook(g_data.mlx_win, 3, 1L << 1, key_off, NULL);
	mlx_hook(g_data.mlx_win, 17, 0, quit, &g_data);
	mlx_hook(g_data.mlx_win, 6, 0, mouse, NULL);
	mlx_loop_hook(g_data.mlx, update, NULL);
	mlx_loop(g_data.mlx);
}
