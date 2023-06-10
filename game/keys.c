/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/10 15:28:10 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keys(int key, t_data *data)
{
	if (key == 123)
	{
		g_data.player.dirturn = -1;
		g_data.player.anglerete += g_data.player.dirturn
			* g_data.player.speedretate;
		addimg();
		printf("angle %f\n", g_data.player.anglerete);
	}
	if (key == 124)
	{
		g_data.player.dirturn = 1;
		g_data.player.anglerete += g_data.player.dirturn
			* g_data.player.speedretate;
		addimg();
		printf("angle %f\n", g_data.player.anglerete);
	}
	if (key == 125 || key == 1)
		move_down(data);
	if (key == 126 || key == 13)
		move_top(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		quit(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
