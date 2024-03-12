/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:36 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 18:07:02 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_map_ext(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = (int) ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".cub", 4) != 0)
		return (0);
	return (1);
}

size_t	ft_mapfile_size(char *src)
{
	char	*tmp;
	size_t	i;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (0);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free (tmp);
	close (fd);
	return (i);
}

char	**ft_copy_mapfile(int fd, size_t size)
{
	char	**map;
	char	*tmp;
	int		i;

	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp);
		if (!map[i])
		{
			free(tmp);
			ft_free(map);
			return (NULL);
		}
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_readmapfile(char *src)
{
	int		fd;
	char	**tmp;
	size_t	i;

	tmp = NULL;
	fd = open(src, O_RDONLY);
	if (!check_map_ext(src))
		ft_error("Not a map in format *.cub!\n");
	else if (fd < 0)
		ft_error("Could not open map file!\n");
	else
	{
		i = ft_mapfile_size(src);
		tmp = ft_copy_mapfile(fd, i);
	}
	close (fd);
	return (tmp);
}
