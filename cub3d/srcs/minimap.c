/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:22:41 by galtange          #+#    #+#             */
/*   Updated: 2024/03/28 22:23:01 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*display_minimap(t_cub3d *game)
{
	t_vec	m;
	t_vec	d;

	m.x = 0;
	d.x = 0;
	d.y = 0;
	while (game->map[m.x])
	{
		m.y = 0;
		while (game->map[m.x][m.y] != '\0')
		{
			if (game->map[m.x][m.y] == '1')
				mlx_put_image_to_window(game->ptr, game->win,
					game->mini.wall.pointer, d.x, d.y);
			else
				mlx_put_image_to_window(game->ptr, game->win,
					game->mini.space.pointer, d.x, d.y);
			d.x += 16;
			m.y++;
		}
		d.x = 0;
		d.y += 16;
		m.x++;
	}
	return (game->ptr);
}
