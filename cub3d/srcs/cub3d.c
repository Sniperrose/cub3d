/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:12:17 by galtange          #+#    #+#             */
/*   Updated: 2024/03/28 22:17:58 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key(t_cub3d *cub3d)
{
	exit (ft_freegame(cub3d, "Exit: RED CROSS\n"));
}

int	ft_move_test(t_cub3d *cub3d, char *str)
{
	mlx_string_put(cub3d->ptr, cub3d->win, 100, 100, cub3d->tex.c_color, str);
	return (1);
}

int	handle_keypress(int keysym, t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->ptr, cub3d->win);
	if (keysym == XK_d || keysym == XK_D)
		cub3d->player.pos_x += 0.5;
	else if (keysym == XK_W || keysym == XK_w)
		cub3d->player.pos_y -= 0.5;
	else if (keysym == XK_A || keysym == XK_a)
		cub3d->player.pos_x -= 0.5;
	else if (keysym == XK_S || keysym == XK_s)
		cub3d->player.pos_y += 0.5;
	if (keysym == XK_Escape)
		exit (ft_freegame(cub3d, "Exit: ESC\n"));
	return (1);
}

void	*display_game(t_cub3d *cub3d)
{
	return (cub3d->ptr);
}

void	*display_player(t_cub3d *game)
{
	int	x;
	int	y;

	x = game->player.pos_x * 16;
	y = game->player.pos_y * 16;
	mlx_put_image_to_window(game->ptr, game->win,
		game->mini.icon.pointer, x, y);
	return (game->ptr);
}

void	render(t_cub3d cub3d)
{
	// display_game(&cub3d);
	display_minimap(&cub3d);
	display_player(&cub3d);
}

int	update(t_cub3d *cub3d)
{
	render(*cub3d);
	return (1);
}

int	ft_raycast(t_cub3d cub3d)
{
	mlx_hook(cub3d.win, KeyPress, KeyPressMask, &handle_keypress, &cub3d);
	mlx_hook(cub3d.win, 17, 1L << 19, &handle_key, &cub3d);
	mlx_loop_hook(cub3d.ptr, update, (void *)&cub3d);
	mlx_loop(cub3d.ptr);
	return (0);
}
