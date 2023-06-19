/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:23 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 21:13:56 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(double x, double y)
{
	if (g_data.cart[(int)(y) / CUBE][(int)(x) / CUBE] == '1'
		|| g_data.cart[(int)(y) / CUBE][(int)(x) / CUBE] == ' ')
		return (1);
	return (0);
}

int	isdown(double angle)
{
	if (angle >= 0 && angle <= M_PI)
		return (1);
	return (0);
}

int	isright(double angle)
{
	if (angle <= M_PI / 2.0 || angle >= 1.5 * M_PI)
		return (1);
	return (0);
}
