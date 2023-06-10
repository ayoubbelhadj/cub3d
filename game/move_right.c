/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:51:44 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/10 15:25:06 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_right(t_data *data)
{
	double	movespeed;

	data->player.dirwalk = -1;
	movespeed = data->player.dirwalk * data->player.speedmove;
	data->player.pos.y += sin(data->player.anglerete - M_PI_2) * movespeed;
	data->player.pos.x += cos(data->player.anglerete - M_PI_2) * movespeed;
	addimg();
}
