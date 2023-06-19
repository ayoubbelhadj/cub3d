/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:18:06 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:03 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	imgs_init(void)
{
	g_data.img.img = mlx_new_image(g_data.mlx, MSIZE, MSIZE);
	g_data.img.addr = mlx_get_data_addr(g_data.img.img,
			&g_data.img.bits_per_pixel, &g_data.img.line_length,
			&g_data.img.endian);
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
}

void	win_init(void)
{
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, WIN_W, WIN_H + BAR_H, "CUB3D");
}

void	resetimg(void)
{
	mlx_destroy_image(g_data.mlx, g_data.img.img);
	mlx_destroy_image(g_data.mlx, g_data.img2.img);
	g_data.img.img = mlx_new_image(g_data.mlx, MSIZE, MSIZE);
	g_data.img.addr = mlx_get_data_addr(g_data.img.img,
			&g_data.img.bits_per_pixel, &g_data.img.line_length,
			&g_data.img.endian);
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
}

void	minigun_init(void)
{
	int	x;

	g_data.minigun = malloc(sizeof(t_sprite) * 7);
	if (!g_data.minigun)
		exit(1);
	g_data.minigun[0].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg0.xpm",
			&x, &x);
	g_data.minigun[1].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg1.xpm",
			&x, &x);
	g_data.minigun[2].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg2.xpm",
			&x, &x);
	g_data.minigun[3].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg3.xpm",
			&x, &x);
	g_data.minigun[4].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg4.xpm",
			&x, &x);
	g_data.minigun[5].img = mlx_xpm_file_to_image(g_data.mlx, "file/mg5.xpm",
			&x, &x);
	g_data.minigunp = g_data.minigun[0].img;
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
	gun_init();
	nbr_init();
	minigun_init();
}
