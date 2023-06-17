/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:18:06 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 01:19:26 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	imgs_init(void)
{
	g_data.img.img = mlx_new_image(g_data.mlx, g_data.x_width, g_data.y_height);
	g_data.img.addr = mlx_get_data_addr(g_data.img.img,
			&g_data.img.bits_per_pixel, &g_data.img.line_length,
			&g_data.img.endian);
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
	g_data.img3.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img3.addr = mlx_get_data_addr(g_data.img3.img,
			&g_data.img3.bits_per_pixel, &g_data.img3.line_length,
			&g_data.img3.endian);
	g_data.img4.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img4.addr = mlx_get_data_addr(g_data.img4.img,
			&g_data.img4.bits_per_pixel, &g_data.img4.line_length,
			&g_data.img4.endian);
}

void	nbr_init(void)
{
	int	x;

	g_data.nbr = malloc(sizeof(t_sprite) * 10);
	if (!g_data.nbr)
		exit(1);
	g_data.nbr[0].img = mlx_xpm_file_to_image(g_data.mlx, "file/n0.xpm",
			&x, &x);
	// g_data.nbr[1].img = mlx_xpm_file_to_image(g_data.mlx, "file/n1.xpm",
	// 		&x, &x);
	// g_data.nbr[2].img = mlx_xpm_file_to_image(g_data.mlx, "file/n2.xpm",
	// 		&x, &x);
	// g_data.nbr[3].img = mlx_xpm_file_to_image(g_data.mlx, "file/n3.xpm",
	// 		&x, &x);
	// g_data.nbr[4].img = mlx_xpm_file_to_image(g_data.mlx, "file/n4.xpm",
	// 		&x, &x);
	// g_data.nbr[5].img = mlx_xpm_file_to_image(g_data.mlx, "file/n5.xpm",
	// 		&x, &x);
	// g_data.nbr[6].img = mlx_xpm_file_to_image(g_data.mlx, "file/n6.xpm",
	// 		&x, &x);
	// g_data.nbr[7].img = mlx_xpm_file_to_image(g_data.mlx, "file/n7.xpm",
	// 		&x, &x);
	// g_data.nbr[8].img = mlx_xpm_file_to_image(g_data.mlx, "file/n8.xpm",
	// 		&x, &x);
	// g_data.nbr[9].img = mlx_xpm_file_to_image(g_data.mlx, "file/n9.xpm",
	// 		&x, &x);
}

void	gun_init(void)
{
	int	x;

	g_data.gun = malloc(sizeof(t_sprite) * 7);
	if (!g_data.gun)
		exit(1);
	g_data.gun[0].img = mlx_xpm_file_to_image(g_data.mlx, "file/g0.xpm",
			&x, &x);
	g_data.gun[1].img = mlx_xpm_file_to_image(g_data.mlx, "file/g1.xpm",
			&x, &x);
	g_data.gun[2].img = mlx_xpm_file_to_image(g_data.mlx, "file/g2.xpm",
			&x, &x);
	g_data.gun[3].img = mlx_xpm_file_to_image(g_data.mlx, "file/g3.xpm",
			&x, &x);
	g_data.gun[4].img = mlx_xpm_file_to_image(g_data.mlx, "file/g4.xpm",
			&x, &x);
	g_data.gun[5].img = mlx_xpm_file_to_image(g_data.mlx, "file/g5.xpm",
			&x, &x);
	g_data.gunp = g_data.gun[0].img;
}

void	win_init(void)
{
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, WIN_W, WIN_H + 200, "CUB3D");
}

void	wall_init(void)
{
	g_data.no.img = mlx_xpm_file_to_image(g_data.mlx, g_data.pars.path_no, \
	&g_data.no.img_w, &g_data.no.img_h);
	g_data.no.addr = (unsigned int *)mlx_get_data_addr(g_data.no.img,
			&g_data.no.bits_per_pixel, &g_data.no.line_length,
			&g_data.no.endian);
	g_data.so.img = mlx_xpm_file_to_image(g_data.mlx, g_data.pars.path_so, \
	&g_data.so.img_w, &g_data.so.img_h);
	g_data.so.addr = (unsigned int *)mlx_get_data_addr(g_data.so.img,
			&g_data.so.bits_per_pixel, &g_data.so.line_length,
			&g_data.so.endian);
	g_data.ea.img = mlx_xpm_file_to_image(g_data.mlx, g_data.pars.path_ea, \
	&g_data.ea.img_w, &g_data.ea.img_h);
	g_data.ea.addr = (unsigned int *)mlx_get_data_addr(g_data.ea.img,
			&g_data.ea.bits_per_pixel, &g_data.ea.line_length,
			&g_data.ea.endian);
	g_data.we.img = mlx_xpm_file_to_image(g_data.mlx, g_data.pars.path_we, \
	&g_data.we.img_w, &g_data.we.img_h);
	g_data.we.addr = (unsigned int *)mlx_get_data_addr(g_data.we.img,
			&g_data.we.bits_per_pixel, &g_data.we.line_length,
			&g_data.we.endian);
}

size_t	ft_tabmaxlen(char **map)
{
	size_t	len;
	int		i;
	size_t	len1;

	len = 0;
	i = 0;
	while (map[i])
	{
		len1 = strlen(map[i]);
		if (len < len1)
		{
			len = len1;
		}
		i++;
	}
	return (len);
}

void	check_dir_angle(void)
{
	if (g_data.pars.pos == 'W')
		g_data.player.alpha = M_PI;
	if (g_data.pars.pos == 'E')
		g_data.player.alpha = 0;
	if (g_data.pars.pos == 'S')
		g_data.player.alpha = M_PI / 2;
	if (g_data.pars.pos == 'N')
		g_data.player.alpha = 3 * M_PI / 2;
}

void	init(void)
{
	g_data.cart = g_data.pars.map;
	g_data.viewangle = 60 * (M_PI / 180);
	g_data.player.speedretate = SPEED_R * (M_PI / 180);
	g_data.player.speedretate_m = M_SPEED_R * (M_PI / 180);
	g_data.player.speedmove = (CUBE * SPEED_M) / 20 ;
	g_data.player.dirturn = 0;
	g_data.player.dirwalk = 0;
	g_data.rad = M_PI / 180;
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
}

void	resetimg(void)
{
	mlx_destroy_image(g_data.mlx, g_data.img.img);
	mlx_destroy_image(g_data.mlx, g_data.img2.img);
	g_data.img.img = mlx_new_image(g_data.mlx, g_data.x_width, g_data.y_height);
	g_data.img.addr = mlx_get_data_addr(g_data.img.img,
			&g_data.img.bits_per_pixel, &g_data.img.line_length,
			&g_data.img.endian);
	g_data.img2.img = mlx_new_image(g_data.mlx, WIN_W, WIN_H);
	g_data.img2.addr = mlx_get_data_addr(g_data.img2.img,
			&g_data.img2.bits_per_pixel, &g_data.img2.line_length,
			&g_data.img2.endian);
}
