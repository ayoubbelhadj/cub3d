/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:13:36 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/17 23:43:35 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_wall2(double x, double y)
{
	int	i;
	int	j;
	int	radius;

	i = x;
	j = y;
	radius = -2;
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
	radius = 2;
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
