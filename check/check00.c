/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:23 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 00:39:56 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	check_wall(double x, double y)
// {
// 	int	xmap;
// 	int	ymap;

// 	xmap = x / CUBE;
// 	ymap = y / CUBE;
// 	if (g_data.cart[ymap][xmap] == '1' ||
// 		(g_data.cart[ymap][(int)(g_data.player.x / CUBE)] == '1' &&
// 		g_data.cart[(int)(g_data.player.y / CUBE)][xmap] == '1'))
// 		return (0);
// 	else
// 		return (1);
// }


int	check_wall2(double x, double y)
{
	int	i;
	int	j;
	int	radius;

	i = x;
	j = y;
	radius = -3;
	while (i > radius + x)
	{
		j = y;
		while (j > radius + y)
		{
			if (g_data.cart[(int)(j / CUBE)][(int)(i / CUBE)] == '1')
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

int	check_wall1(double x, double y)
{
	int	i;
	int	j;
	int	radius;

	i = x;
	j = y;
	radius = 3;
	while (i < radius + x)
	{
		j = y;
		while (j < radius + y)
		{
			if (g_data.cart[(int)(j / CUBE)][(int)(i / CUBE)] == '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_wall(double x, double y)
{
	if (check_wall1(x, y) && check_wall2(x, y))
		return (1);
	return (0);
}

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
