/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:26:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/18 16:51:11 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

int	check_digitcomma(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_commas(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			c++;
	}
	if (c != 2)
		return (free(str), 0);
	return (1);
}

int	check_length(char **str)
{
	int	i;
	int	j;

	if (str[0] == 0)
		return (0);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_strlen(str[i]) < 1 || ft_strlen(str[i]) > 3)
			return (0);
		if (ft_atoi(str[i]) > 255)
			return (0);
	}
	return (1);
}

int	check_colors(void)
{
	int	i;

	i = -1;
	if (!g_data.pars.colorc || !g_data.pars.colorf)
		return (0);
	if (!check_digitcomma(g_data.pars.colorc)
		|| !check_digitcomma(g_data.pars.colorf))
		return (0);
	if (!check_commas(g_data.pars.colorc) && check_commas(g_data.pars.colorf))
		return (free(g_data.pars.colorf), 0);
	if (!check_commas(g_data.pars.colorf) && check_commas(g_data.pars.colorc))
		return (free(g_data.pars.colorc), 0);
	if (!check_commas(g_data.pars.colorf) && !check_commas(g_data.pars.colorc))
		return (0);
	g_data.pars.c = ft_split(g_data.pars.colorc, ',');
	g_data.pars.f = ft_split(g_data.pars.colorf, ',');
	free(g_data.pars.colorc);
	free(g_data.pars.colorf);
	if (!check_length(g_data.pars.f) || !check_length(g_data.pars.c))
		return (0);
	return (1);
}
