/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:49:58 by abelhadj          #+#    #+#             */
/*   Updated: 2023/06/13 22:24:06 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	name_check(char *name)
{
	int		namelen;
	char	*str;

	namelen = ft_strlen(name);
	if (namelen <= 4)
		ft_error("ERROR!\nThe map name has to ended with .cub extention.\n");
	str = name + (namelen - 4);
	if (ft_strcmp(str, ".cub"))
		ft_error("ERROR!\nThe map name has to ended with .cub extention.\n");
	return (0);
}
