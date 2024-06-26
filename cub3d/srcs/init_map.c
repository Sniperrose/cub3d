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
	while (tmp[i] && i < size)
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

int	ft_aftermap(char **map, char **tmp)
{
	int		i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		if (!ft_str_is_printable(map[i]))
			return (0);
		j = 0;
		while (map[i][j] && ft_iswhitespace(map[i][j]))
			j++;
		if (ft_strlen(map[i]) == j)
			return (0);
		i++;
	}
	if (tmp[i])
		return (0);
	return (1);
}

int	ft_initmap(t_cub3d *cub3d, char **tmp)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (tmp[i] && (!ft_ismappart(tmp[i]) || !ft_str_is_printable(tmp[i])))
		i++;
	while (tmp[i + size] && ft_ismappart(tmp[i + size]))
		size++;
	cub3d->map = ft_getmap(&tmp[i], size);
	if (!cub3d->map)
		return (0);
	if (!ft_aftermap(cub3d->map, &tmp[i]))
		return (0);
	if (!ft_check_map(cub3d->map, cub3d))
		return (0);
	return (1);
}
