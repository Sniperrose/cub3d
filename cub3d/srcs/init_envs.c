/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:08:09 by galtange          #+#    #+#             */
/*   Updated: 2024/03/28 22:09:35 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_set_null(t_cub3d *data)
{
	data->tex.ea.pointer = NULL;
	data->tex.no.pointer = NULL;
	data->tex.so.pointer = NULL;
	data->tex.we.pointer = NULL;
	data->mini.icon.pointer = NULL;
	data->mini.space.pointer = NULL;
	data->mini.wall.pointer = NULL;
	data->tex.c_color = -1;
	data->tex.c_color = -1;
	data->map = NULL;
	data->time = 0;
	data->oldtime = 0;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

int	ft_initdata(t_cub3d *cub3d, char **tmp)
{
	cub3d->ptr = mlx_init();
	if (!cub3d->ptr)
		return (ft_error("init ptr failed\n"));
	printf("... init mlx ptr success\n");
	cub3d->win = mlx_new_window(cub3d->ptr, SW, SH, "cub3D");
	if (!cub3d->win)
		return (ft_error("init mlx_win failed\n"));
	printf("... init mlx win success\n");
	ft_set_null(cub3d);
	if (!ft_check_and_init_elems(cub3d, tmp))
		return (ft_error(" init texure failed!\n"));
	printf("... init texure success\n");
	if (!ft_initmap(cub3d, tmp))
		return (ft_error("Map init failed! "));
	printf("... init map success\n");
	cub3d->player.pos_x = cub3d->player.p.x + 0.25;
	cub3d->player.pos_y = cub3d->player.p.y + 0.25;
	return (0);
}
