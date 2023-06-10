/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:46:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/10 15:36:39 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			ft_error("ERROR!\nPath map name invalid.\n");
		map = read_map(fd);
		g_data.map = map;
		game();
	}
	return (0);
}
