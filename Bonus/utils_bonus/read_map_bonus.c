/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:14:54 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/18 16:51:28 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

char	*read_map(int fd)
{
	char	*buff;
	char	*map;
	char	*tmp;

	map = ft_calloc(1, 1);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (ft_strlen(buff) <= 1)
			ft_error("ERROR!\nEmpty line in map.\n");
		tmp = ft_strdup(map);
		free(map);
		map = ft_strjoin(tmp, buff);
		free(tmp);
		free(buff);
	}
	return (map);
}
