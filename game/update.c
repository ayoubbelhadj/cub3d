/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:03:20 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/14 14:26:33 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rend_img(void)
{
	fillmap();
	drawrays();
	line(40, g_data.player.alpha, 0x000000);
	drawcircle(g_data.player.x, g_data.player.y, 6);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img, 0, 0);
}

void	update(void)
{
	sendrays();
	rend_img();
}
