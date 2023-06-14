/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/14 14:15:15 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keys(int key, t_data *data)
{
	if (key == 123)
		turn_right(data, 0);
	if (key == 124)
		turn_left(data, 0);
	if (key == 1)
		move_down(data);
	if (key == 13)
		move_top(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		quit(data);
	update();
	return (0);
}
