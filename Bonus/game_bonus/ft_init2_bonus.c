/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:02:11 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:50:57 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	nbr_init2(void)
{
	int	x;

	g_data.nbr[5].img = mlx_xpm_file_to_image(g_data.mlx, "file/5.xpm",
			&x, &x);
	g_data.nbr[6].img = mlx_xpm_file_to_image(g_data.mlx, "file/6.xpm",
			&x, &x);
	g_data.nbr[7].img = mlx_xpm_file_to_image(g_data.mlx, "file/7.xpm",
			&x, &x);
	g_data.nbr[8].img = mlx_xpm_file_to_image(g_data.mlx, "file/8.xpm",
			&x, &x);
	g_data.nbr[9].img = mlx_xpm_file_to_image(g_data.mlx, "file/9.xpm",
			&x, &x);
	g_data.nbr[10].img = mlx_xpm_file_to_image(g_data.mlx, "file/bar.xpm",
			&x, &x);
}

void	nbr_init(void)
{
	int	x;

	g_data.nbr = malloc(sizeof(t_sprite) * 11);
	if (!g_data.nbr)
		exit(1);
	g_data.nbr[0].img = mlx_xpm_file_to_image(g_data.mlx, "file/0.xpm",
			&x, &x);
	g_data.nbr[1].img = mlx_xpm_file_to_image(g_data.mlx, "file/1.xpm",
			&x, &x);
	g_data.nbr[2].img = mlx_xpm_file_to_image(g_data.mlx, "file/2.xpm",
			&x, &x);
	g_data.nbr[3].img = mlx_xpm_file_to_image(g_data.mlx, "file/3.xpm",
			&x, &x);
	g_data.nbr[4].img = mlx_xpm_file_to_image(g_data.mlx, "file/4.xpm",
			&x, &x);
	nbr_init2();
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
