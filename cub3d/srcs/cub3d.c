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

void	ft_move_up(char **map, t_cub3d *data, double moveSpeed)
{
	// data->r.posY -= 0.5;

	// (void) map;
	// (void) moveSpeed;
	if(map[(int)(data->r.posX + data->r.dirX * moveSpeed)][(int)data->r.posY] == 0) 
		data->r.posX += data->r.dirX * moveSpeed * 16;
    if(map[(int)(data->r.posX)][(int)(data->r.posY + data->r.dirY * moveSpeed)] == 0)
		data->r.posY += data->r.dirY * moveSpeed * 16;
	printf("posX = %f ", data->r.posX);
	printf("posY = %f\n", data->r.posY);

	printf("dirX = %f && dirX * MS = %f\n", data->r.dirX, data->r.dirX * moveSpeed);
	printf("dirY = %f \n", data->r.dirY);


	// if (cub3d->map[][])
	// ray->posY -= 0.5;
}

int	handle_keypress(int keysym, t_cub3d *cub3d)
{
	cub3d->oldTime = cub3d->time;
	gettimeofday(&cub3d->time, NULL);
	cub3d->frameTime = (cub3d->time.tv_sec - cub3d->oldTime.tv_sec) / 1000.0;
	// printf ("%f\n", 1.0/cub3d->frameTime);
	mlx_clear_window(cub3d->ptr, cub3d->win);
	cub3d->moveSpeed = cub3d->frameTime * 50.0;
	printf("moveSpeed %f\n", cub3d->moveSpeed);
	cub3d->rotSpeed = cub3d->frameTime * 3.0;
	if (keysym == XK_d || keysym == XK_D)
		cub3d->r.posX += 0.5;
	else if (keysym == XK_W || keysym == XK_w)
		ft_move_up(cub3d->map, cub3d, cub3d->moveSpeed);
	else if (keysym == XK_A || keysym == XK_a)
		cub3d->r.posX -= 0.5;
	else if (keysym == XK_S || keysym == XK_s)
		cub3d->r.posY += 0.5;
	else if (keysym == XK_Left)
		printf("left\n");
	else if (keysym == XK_Right)
		printf("rigth\n");
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

	x = game->r.posX * 16;
	y = game->r.posY * 16;
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
