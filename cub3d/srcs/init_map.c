/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:10:36 by galtange          #+#    #+#             */
/*   Updated: 2024/03/28 22:11:54 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_ismappart(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else if (str[i] == '0')
			i++;
		else if (str[i] == 'N')
			i++;
		else if (str[i] == 'S')
			i++;
		else if (str[i] == 'E')
			i++;
		else if (str[i] == 'W')
			i++;
		else if (ft_iswhitespace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

char	**ft_getmap(char **tmp, int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!size)
		return (NULL);
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (tmp[i] && ft_str_is_printable(tmp[i]) && i < size)
	{
		map[i] = ft_strdup(tmp[i]);
		if (!map[i])
		{
			ft_free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	ft_initmap(t_cub3d *cub3d, char **tmp)
{
	int	i;
	int	size;
	int	x;

	i = 0;
	size = 0;
	while (tmp[i] && (!ft_ismappart(tmp[i]) || !ft_str_is_printable(tmp[i])))
		i++;
	while (tmp[i + size] && ft_ismappart(tmp[i + size]))
		size++;
	cub3d->map = ft_getmap(&tmp[i], size);
	if (!cub3d->map)
		return (0);
	if (!ft_check_map(cub3d->map, cub3d))
		return (0);
	x = 0;
	while (cub3d->map[x])
		x++;
	if (tmp[i + x])
		return (0);
	return (1);
}
