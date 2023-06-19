/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:03:20 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 14:06:32 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	putimg(void)
{
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img2.img, 0, 0);
}

void	rend_img(void)
{
	resetimg();
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	rend3d();
	img3d();
	putimg();
}

int	update(void)
{
	move();
	sendrays();
	g3d();
	rend_img();
	return (0);
}
