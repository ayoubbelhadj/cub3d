/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:24:53 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/17 21:06:11 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	skip_part1(char **tab)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			c++;
		else if ((tab[i][0] == ' ' || tab[i][0] == '\t') && all_white(tab[i]))
		{
		}
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			c++;
	}
	if (all_white(tab[i]))
		while (all_white(tab[i]))
			i++;
	return (i);
}

void	put_map(char **file, char *str)
{
	int	i;
	int	j;
	int	n;

	i = skip_part1(file);
	g_data.pars.map = malloc(sizeof(char *) * ((lines_number(str) - i) + 1));
	j = 0;
	n = 0;
	while (file[i] && i <= end(file, str))
	{
		g_data.pars.map[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	g_data.pars.map[j] = NULL;
	ft_free(file);
}

int	is_closed(char c)
{
	int	i;
	int	j;

	i = 0;
	while (g_data.pars.map[++i] && i < map_len())
	{
		j = -1;
		while (g_data.pars.map[i][++j])
		{
			if (g_data.pars.map[i][j] == c)
			{
				if ((g_data.pars.map[i][j - 1] == ' '
					|| g_data.pars.map[i][j - 1] == 0)
					|| (g_data.pars.map[i][j + 1] == ' '
					|| g_data.pars.map[i][j + 1] == 0)
					|| (g_data.pars.map[i - 1][j] == ' '
					|| j + 1 >= (int)ft_strlen(g_data.pars.map[i - 1]))
					|| (g_data.pars.map[i + 1][j] == ' '
					|| j + 1 >= (int)ft_strlen(g_data.pars.map[i + 1])))
					return (0);
			}
		}
	}
	return (1);
}

int	empty_line(void)
{
	int	i;

	i = -1;
	while (g_data.pars.map[++i])
	{
		if (all_white(g_data.pars.map[i]))
			return (0);
	}
	return (1);
}

int	checker_map1(char *str)
{
	put_map(file_tab(str), str);
	if (!empty_line())
		return (0);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(g_data.pars.pos) || !is_closed('0'))
		return (0);
	return (1);
}
