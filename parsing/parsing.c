/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:40 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/17 00:24:05 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	printerr(int e)
{
	printf("Error\n");
	if (e == 1)
		printf("Check extension\n");
	else if (e == 2)
		printf("Check file\n");
	else if (e == 3)
		printf("Check colors\n");
	else if (e == 4)
		printf("Check the paths\n");
	else if (e == 5)
		printf("Check map\n");
}

int	parsing(char *str)
{
	if (!dot_cub(str))
		return (printerr(1), 0);
	if (!check_lines(str))
		return (printerr(2), 0);
	if (!check_colors())
		return (printerr(3), 0);
	if (!accessible())
		return (printerr(4), 0);
	if (!checker_map1(str))
		return (printerr(5), 0);
	return (1);
}
