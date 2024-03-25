/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:01:18 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 20:03:26 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	ft_initmini(t_cub3d *cub3d)
{
	cub3d->mini.icon.pointer = NULL;
	cub3d->mini.space.pointer = NULL;
	cub3d->mini.wall.pointer = NULL;
	cub3d->mini.icon = ft_new_sprite(cub3d->ptr, "texure/minimap/icon.xpm");
	cub3d->mini.wall = ft_new_sprite(cub3d->ptr, "texure/minimap/wall.xpm");
	cub3d->mini.space = ft_new_sprite(cub3d->ptr, "texure/minimap/space.xpm");
	if (cub3d->mini.icon.pointer == NULL || cub3d->mini.wall.pointer == NULL)
		return (1);
	if (cub3d->mini.space.pointer == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	char	**tmp;

	if (argc == 1)
		return (ft_error("Please choose the mapfile!\n"));
	else if (argc != 2)
		return (ft_error("This project accept only 2args!\n"));
	else
	{
		tmp = ft_readmapfile(argv[1]);
		if (!tmp)
			return (ft_error("map error!\n"));
		if (ft_initdata(&cub3d, tmp) || ft_initmini(&cub3d))
		{
			ft_free(tmp);
			ft_freegame(&cub3d, "");
			return (ft_error("init error!\n"));
		}
		ft_free(tmp);
		ft_raycast(cub3d);
		ft_freegame(&cub3d, "");
	}
	return (0);
}
