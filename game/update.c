/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:03:20 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 00:38:26 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	walkupdown(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalk * g_data.player.speedmove;
	x = g_data.player.x + cos(g_data.player.alpha) * movespeed;
	y = g_data.player.y + sin(g_data.player.alpha) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkleftright(void)
{
	double	movespeed;
	double	x;
	double	y;

	movespeed = g_data.player.dirwalkx * g_data.player.speedmove;
	y = g_data.player.y + sin(g_data.player.alpha - M_PI_2) * movespeed;
	x = g_data.player.x + cos(g_data.player.alpha - M_PI_2) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	walkx(void)
{
	double	movespeed;
	double	angle;
	double	x;
	double	y;

	movespeed = g_data.player.speedmove;
	if (g_data.player.dirwalk == -1)
		angle = g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 2);
	else
		angle = g_data.player.dirwalk
			* (g_data.player.alpha + (g_data.player.dirwalkx * -1 * M_PI / 4));
	y = g_data.player.y + sin(angle) * movespeed;
	x = g_data.player.x + cos(angle) * movespeed;
	if (check_wall(x, y))
	{
		g_data.player.y = y;
		g_data.player.x = x;
	}
}

void	move(void)
{
	g_data.player.alpha += g_data.player.dirturn
		* g_data.player.speedretate;
	if (g_data.player.dirwalk != 0 && g_data.player.dirwalkx != 0)
		walkx();
	else if (g_data.player.dirwalk != 0)
		walkupdown();
	else if (g_data.player.dirwalkx != 0)
		walkleftright();
}

void	bottombar(void)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < BAR_W)
	{
		j = 0;
		while (j < BAR_H)
		{
			color = rgb(20, 56, 141);
			my_mlx_pixel_put3(i, j, 0xBABABA);
			j++;
		}
		i++;
	}
}

void	rend_img(void)
{
	resetimg();
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	rend3d();
	img3d();
	fillmap();
	drawrays();
	line(10, g_data.player.alpha, 0x000000);
	drawcircle(g_data.player.x, g_data.player.y, 3);
	bottombar();
	mlx_clear_window(g_data.mlx, g_data.mlx_win);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img2.img, 0, 0);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win,
		g_data.img3.img, 0, WIN_H);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win,
		g_data.img.img, 0, WIN_H);
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.gunp, (WIN_W / 2) - 150, WIN_H - 300);
	// mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.nbr[0].img, WIN_W - 150, WIN_H);
}

void	gun_shut(void)
{
	if (g_data.shotf)
	{
		g_data.frame1++;
		if (g_data.frame1 <= 3)
			g_data.gunp = g_data.gun[0].img;
		else if (g_data.frame1 <= 6)
			g_data.gunp = g_data.gun[1].img;
		else if (g_data.frame1 <= 9)
			g_data.gunp = g_data.gun[2].img;
		else if (g_data.frame1 <= 12)
			g_data.gunp = g_data.gun[3].img;
		else if (g_data.frame1 <= 15)
			g_data.gunp = g_data.gun[4].img;
		else if (g_data.frame1 <= 18)
			g_data.gunp = g_data.gun[5].img;
		else if (g_data.frame1 > 18)
		{
			g_data.frame1 = -1;
			g_data.shotf = 0;
		}
	}
}

int	update(void)
{
	move();
	gun_shut();
	sendrays();
	g3d();
	rend_img();
	return (0);
}
