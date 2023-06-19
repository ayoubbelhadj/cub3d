/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:18:49 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 13:47:45 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game(void)
{
	init();
	mlx_hook(g_data.mlx_win, 2, 1L << 0, key_on, NULL);
	mlx_hook(g_data.mlx_win, 3, 1L << 1, key_off, NULL);
	mlx_hook(g_data.mlx_win, 17, 0, quit, &g_data);
	mlx_loop_hook(g_data.mlx, update, NULL);
	mlx_loop(g_data.mlx);
}
