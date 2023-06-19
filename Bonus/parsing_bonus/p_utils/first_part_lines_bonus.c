/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_lines_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:35:22 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/18 16:51:18 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

char	*get_line(char **tab, char *str)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == str[0])
			{
				if (!str[1])
					return (ft_strdup(tab[i]));
				else if (tab[i][j + 1]
					&& tab[i][j + 1] == str[1])
					return (ft_strdup(tab[i]));
			}
		}
	}
	return (NULL);
}

char	*fst_partof_line(char *line)
{
	char	*dir;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	dir = NULL;
	i = 0;
	if (line[0] == ' ' || line[0] == '\t')
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
	}
	j = i;
	while ((line[i] != ' ' && line[i] != '\t') && line[i])
		i++;
	dir = ft_substr(line, j, i - j);
	return (dir);
}

char	*get_str(char *str)
{
	char	*path;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	if (str[0] == ' ' || str[0] == '\t')
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	j = i;
	while ((str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n') && str[i])
		i++;
	if (i == j)
		return (free(str), NULL);
	path = ft_substr(str, j, i - j);
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (free(path), free(str), NULL);
	return (free(str), path);
}

char	*rest_of_line(char *line, char *str)
{
	int		i;
	char	*rest;
	char	*d;

	if (!line)
		return (0);
	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	d = fst_partof_line(line + i);
	if (!d)
		return (free(line), NULL);
	if (ft_strcmp(d, str))
		return (free(d), free(line), NULL);
	rest = ft_substr(line, i + ft_strlen(d),
			ft_strlen(line) - i + ft_strlen(d));
	free(d);
	free(line);
	return (rest);
}
