/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessible_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:03:32 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/18 16:51:10 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

int	accessible(void)
{
	int	fd;

	fd = open(g_data.pars.path_ea, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_data.pars.path_no, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_data.pars.path_so, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(g_data.pars.path_we, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
