/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:09:53 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/07 17:00:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	win(t_graph *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_putstr_fd("--YOU WIN--\n", 1);
	exit(0);
}
