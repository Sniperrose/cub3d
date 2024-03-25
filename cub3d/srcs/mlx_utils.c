/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:57:29 by galtange          #+#    #+#             */
/*   Updated: 2024/03/05 17:57:35 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_image	ft_new_sprite(void *ptr, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(ptr, path, &img.size.x, &img.size.y);
	return (img);
}

void	ft_free_texure(t_cub3d *cub3d)
{
	if (cub3d->tex.ea.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->tex.ea.pointer);
	if (cub3d->tex.no.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->tex.no.pointer);
	if (cub3d->tex.so.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->tex.so.pointer);
	if (cub3d->tex.we.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->tex.we.pointer);
	if (cub3d->mini.icon.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->mini.icon.pointer);
	if (cub3d->mini.wall.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->mini.wall.pointer);
	if (cub3d->mini.space.pointer)
		mlx_destroy_image(cub3d->ptr, cub3d->mini.space.pointer);
}

int	ft_freegame(t_cub3d *cub3d, char *str)
{
    if (cub3d->map)
	    ft_free(cub3d->map);
    ft_free_texure(cub3d);
	if (cub3d->win)
	{
		mlx_destroy_window (cub3d->ptr, cub3d->win);
		mlx_destroy_display (cub3d->ptr);
	}
	if (cub3d->ptr)
		free(cub3d->ptr);
	ft_putstr_fd(str, 1);
	return (0);
}