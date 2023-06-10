/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openportal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:54:17 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/09 17:35:39 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	openportal(t_graph *data)
{
	// data->cart[data->exit.y][data->exit.x] = 'O';
	mlx_clear_window(data->mlx, data->mlx_win);
	addimg();
}
