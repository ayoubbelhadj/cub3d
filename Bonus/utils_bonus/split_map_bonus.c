/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:12:08 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:29 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

char	**split_map(char *map)
{
	char	**p;

	if (!map)
		return (0);
	p = ft_split(map, '\n');
	return (p);
}
