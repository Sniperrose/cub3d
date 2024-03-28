/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:13:29 by galtange          #+#    #+#             */
/*   Updated: 2024/03/28 22:10:39 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_mapfill(char **map, int i, int j, char c)
{
	int	inj;

	inj = 0;
	if (map[i][j - 1] != '1' && map[i][j - 1] == '0')
	{
		map[i][j - 1] = c;
		inj++;
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] == '0')
	{
		map[i][j + 1] = c;
		inj++;
	}
	if (map[i - 1][j] != '1' && map[i - 1][j] == '0')
	{
		map[i - 1][j] = c;
		inj++;
	}
	if (map[i + 1][j] && map[i + 1][j] != '1' && map[i + 1][j] == '0')
	{
		map[i + 1][j] = c;
		inj++;
	}
	return (inj);
}

int	ft_leak(char **map, int i, int j)
{
	if (!map[i][j - 1])
		return (0);
	if (!map[i][j + 1])
		return (0);
	if (!map[i - 1][j])
		return (0);
	if (!map[i + 1][j])
		return (0);
	if (ft_iswhitespace(map[i][j - 1]))
		return (0);
	if (ft_iswhitespace(map[i][j + 1]))
		return (0);
	if (ft_iswhitespace(map[i - 1][j]))
		return (0);
	if (ft_iswhitespace(map[i + 1][j]))
		return (0);
	return (1);
}

int	ft_checkwall(char **tmp, size_t size, char c)
{
	int		i;
	size_t	x;
	size_t	y;

	i = -1;
	while (i)
	{
		i = 0;
		x = 0;
		y = 0;
		while (y < size)
		{
			if (tmp[y][x] == c && ft_leak(tmp, y, x))
				i += ft_mapfill(tmp, y, x, c);
			else if (tmp[y][x] == c && !ft_leak(tmp, y, x))
				return (0);
			x++;
			if (tmp[y][x] == '\0')
			{
				x = 0;
				y++;
			}
		}
	}
	return (1);
}

int	ft_validmap(char **map, char c)
{
	int		size;
	int		res;
	char	**tmp;

	size = 0;
	res = 0;
	while (map[size])
		size++;
	tmp = ft_getmap(map, size);
	if (!tmp)
		return (0);
	res = ft_checkwall(tmp, size, c);
	ft_free(tmp);
	return (res);
}

int	ft_check_map(char **map, t_cub3d *cub3d)
{
	t_vec	pos;
	int		p_flag;

	pos.y = 0;
	p_flag = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] != '0' && map[pos.y][pos.x] != '1' &&
				!ft_iswhitespace(map[pos.y][pos.x]))
			{
				cub3d->player.p = pos;
				cub3d->player.start_dir = map[pos.y][pos.x];
				p_flag++;
			}
			pos.x++;
		}
		pos.y++;
	}
	if (p_flag != 1 || !ft_validmap(map, cub3d->player.start_dir))
		return (0);
	return (1);
}
