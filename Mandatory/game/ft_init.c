/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:18:06 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 14:04:16 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	imgs_init(void)
{
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
}

void	win_init(void)
{
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, WIN_W, WIN_H, "CUB3D");
}

void	resetimg(void)
{
	mlx_destroy_image(g_data.mlx, g_data.img2.img);
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
}

void	init(void)
{
	var_init();
	check_dir_angle();
	position();
	g_data.x_width = ft_tabmaxlen(g_data.cart) * CUBE;
	g_data.y_height = ft_tablen(g_data.cart) * CUBE;
	g_data.nbr_rays = WIN_W;
	g_data.ray = ft_calloc(sizeof(t_ray), g_data.nbr_rays + 1);
	g_data.g3d = ft_calloc(sizeof(t_ray), g_data.nbr_rays + 1);
	win_init();
	imgs_init();
	wall_init();
}
