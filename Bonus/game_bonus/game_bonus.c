/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:18:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:50:59 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	game(void)
{
	init();
	mlx_hook(g_data.mlx_win, 2, 1L << 0, key_on, NULL);
	mlx_hook(g_data.mlx_win, 3, 1L << 1, key_off, NULL);
	mlx_hook(g_data.mlx_win, 17, 0, quit, &g_data);
	mlx_hook(g_data.mlx_win, 4, 1L << 8, mouse_on, NULL);
	mlx_hook(g_data.mlx_win, 5, 1L << 8, mouse_off, NULL);
	mlx_hook(g_data.mlx_win, 6, 0, mouse, NULL);
	mlx_loop_hook(g_data.mlx, update, NULL);
	mlx_loop(g_data.mlx);
}
