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

void	ft_move_up(char **map, t_cub3d *cub3d, double moveSpeed)
{
	(void) map;
	(void) moveSpeed;
	cub3d->r.posY -= 0.1 ;
}

int	handle_keypress(int keysym, t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->ptr, cub3d->win);
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

void	*display_player(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	vx;
	int	vy;

	x = cub3d->r.posX * 16 + 6;
	y = cub3d->r.posY * 16 + 6;
	// 0xFFFF64
	// mlx_pixel_put(cub3d->ptr, cub3d->win, x, y, 0xFF0000);
	int	test = 0;
	vx = x + 1;
	vy = y + 1;
	while (test < 10)
	{
		vx = vx + cub3d->r.dirX;
		vy = vy + cub3d->r.dirY;
		mlx_pixel_put(cub3d->ptr, cub3d->win, vx, vy, 0xFFFF64);
		test++;
	}
	mlx_put_image_to_window(cub3d->ptr, cub3d->win,
		cub3d->mini.icon.pointer, x, y);
	return (cub3d->ptr);
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


// void	ft_move_up(char **map, t_cub3d *data, double moveSpeed)
// {
// 	// data->r.posY -= 0.5;

// 	// (void) map;
// 	// (void) moveSpeed;
// 	if(map[(int)(data->r.posX + data->r.dirX * moveSpeed)][(int)data->r.posY] == 0) 
// 		data->r.posX += data->r.dirX * moveSpeed * 16;
//     if(map[(int)(data->r.posX)][(int)(data->r.posY + data->r.dirY * moveSpeed)] == 0)
// 		data->r.posY += data->r.dirY * moveSpeed * 16;
// 	printf("posX = %f ", data->r.posX);
// 	printf("posY = %f\n", data->r.posY);

// 	printf("dirX = %f && dirX * MS = %f\n", data->r.dirX, data->r.dirX * moveSpeed);
// 	printf("dirY = %f \n", data->r.dirY);


// 	// if (cub3d->map[][])
// 	// ray->posY -= 0.5;
// }