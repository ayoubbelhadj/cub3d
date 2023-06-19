/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:03:20 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 18:39:58 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	putimg(void)
{
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img2.img, 0, 0);
	if (g_data.nshot)
		mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.gunp,
			(WIN_W / 2) - 150, WIN_H - 300);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win,
		g_data.nbr[10].img, 0, WIN_H);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.nb1, 870, 836);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.nb2, 928, 836);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.nb3, 984, 836);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win,
		g_data.minigunp, 452, WIN_H + 35);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win,
		g_data.img.img, 20, WIN_H + 15);
}

void	rend_img(void)
{
	resetimg();
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	rend3d();
	img3d();
	fillmap();
	line(15, g_data.player.alpha, 0xFFFFFF);
	drawcircle(MSIZE / 2, MSIZE / 2, 4);
	putimg();
}

int	update(void)
{
	move();
	gun_shut();
	nbr_bullet();
	sendrays();
	g3d();
	rend_img();
	return (0);
}
