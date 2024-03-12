/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:07:41 by galtange          #+#    #+#             */
/*   Updated: 2024/03/04 18:10:25 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_rgb2hex(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff));
	return (-1);
}

int	ft_getcolorval(const char *str)
{
	int	j;
	int	i;
	int	color[3];

	if (!str || ft_countsep(str, ',') != 3)
		return (-1);
	j = 0;
	while (!ft_isdigit(str[j]))
		j++;
	i = 0;
	while (i < 3)
	{
		while (!ft_isdigit(str[j]) && str[j] != '-' && str[j] != '+')
			j++;
		color[i] = ft_atoi(&str[j]);
		while (ft_isdigit(str[j]))
			j++;
		i++;
	}
	i = ft_rgb2hex(color[0], color[1], color[2]);
	return (i);
}

char	*ft_getpath(const char *str)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
			size++;
		i++;
	}
	tmp = malloc((size + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp[size--] = '\0';
	while (--i >= 0)
	{
		if (!ft_iswhitespace(str[i]))
		{
			tmp[size] = str[i];
			size--;
		}
	}
	return (tmp);
}

int	ft_init_texure(char *path, t_cub3d *data)
{
	if (ft_strnstr(path, "F", 1))
		data->tex.f_color = ft_getcolorval(path);
	else if (ft_strnstr(path, "C", 1))
		data->tex.c_color = ft_getcolorval(path);
	else if (ft_strnstr(path, "NO", 2))
		data->tex.no = ft_new_sprite(data->ptr, &path[2]);
	else if (ft_strnstr(path, "SO", 2))
		data->tex.so = ft_new_sprite(data->ptr, &path[2]);
	else if (ft_strnstr(path, "WE", 2))
		data->tex.we = ft_new_sprite(data->ptr, &path[2]);
	else if (ft_strnstr(path, "EA", 2))
		data->tex.ea = ft_new_sprite(data->ptr, &path[2]);
	else
		return (0);
	return (1);
}

int	ft_check_and_init_elems(t_cub3d *cub3d, char **tmp)
{
	int		i;
	int		comp_tex;
	char	*path;

	i = 0;
	comp_tex = 0;
	while (tmp[i] && comp_tex < 6)
	{
		path = ft_getpath(tmp[i]);
		if (path)
		{
			comp_tex += ft_init_texure(path, cub3d);
			free(path);
		}
		i++;
	}
	if (cub3d->tex.c_color < 0 || cub3d->tex.f_color < 0 || comp_tex != 6)
		return (0);
	if (cub3d->tex.so.pointer == NULL || cub3d->tex.we.pointer == NULL)
		return (0);
	if (cub3d->tex.no.pointer == NULL || cub3d->tex.ea.pointer == NULL)
		return (0);
	return (1);
}
