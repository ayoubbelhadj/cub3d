/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:09:17 by aoudija           #+#    #+#             */
/*   Updated: 2023/06/14 10:44:35 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_frees1(char *s1, char *s2)
{
	int		len;
	char	*sj;
	int		d;
	int		s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	d = ft_strlen(s1);
	s = ft_strlen(s2);
	len = d + s;
	sj = malloc(len + 1);
	if (sj == NULL)
		return (NULL);
	ft_strlcpy(sj, s1, d + 1);
	ft_strlcat(sj, s2, len + 1);
	free(s1);
	return (sj);
}
