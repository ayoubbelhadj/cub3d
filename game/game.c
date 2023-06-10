/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:18:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/10 16:29:45 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game(void)
{
	g_data.cart = split_map(g_data.map);
	if (!g_data.cart)
	{
		free_cart(g_data.cart);
		ft_error("ERROR!!\nMap invalid.\n");
	}
	position();
	g_data.player.anglerete = 0;
	g_data.player.speedretate = 10 * (M_PI / 180);
	g_data.player.speedmove = 10.0;
	g_data.player.dirturn = 0;
	g_data.player.dirwalk = 0;
	g_data.x_width = ft_strlen(g_data.cart[0]) * 64;
	g_data.y_height = ft_tablen(g_data.cart) * 64;
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, g_data.x_width, g_data.y_height,
			"CUB3D");
	g_data.img = mlx_new_image(g_data.mlx, g_data.x_width, g_data.y_height);
	g_data.addr = mlx_get_data_addr(g_data.img, &g_data.bits_per_pixel,
			&g_data.line_length, &g_data.endian);
	addimg();
	mlx_put_image_to_window(g_data.mlx, g_data.mlx_win, g_data.img, 0, 0);
	mlx_hook(g_data.mlx_win, 2, 0, keys, &g_data);
	mlx_hook(g_data.mlx_win, 17, 0, quit, &g_data);
	mlx_loop(g_data.mlx);
}
