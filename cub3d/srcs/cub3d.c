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
	int			i;

	i = 0;
	mlx_clear_window(cub3d->ptr, cub3d->win);
	if (keysym == XK_d || keysym == XK_D)
		i = ft_move_test(cub3d, "rigth");
	else if (keysym == XK_W || keysym == XK_w)
		i = ft_move_test(cub3d, "up");
	else if (keysym == XK_A || keysym == XK_a)
		i = ft_move_test(cub3d, "left");
	else if (keysym == XK_S || keysym == XK_s)
		i = ft_move_test(cub3d, "down");
	if (keysym == XK_Escape)
		exit (ft_freegame(cub3d, "Exit: ESC\n"));
	return (i);
}

void	*display_game(t_cub3d *cub3d)
{
	// mlx_string_put(cub3d->ptr, cub3d->win, 100, 100, cub3d->tex.c_color, "display test");
	return (cub3d->ptr);
}

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

void	*display_player(t_cub3d *game)
{
	int	x;
	int	y;

	x = game->player.p.x * 16;
	y = game->player.p.y * 16;
	mlx_put_image_to_window(game->ptr, game->win, game->mini.icon.pointer, x, y);
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

int ft_raycast(t_cub3d cub3d)
{
    // ft_setview(cub3d);
    // raycast(cub3d);
    mlx_hook(cub3d.win, KeyPress, KeyPressMask, &handle_keypress, &cub3d);
	mlx_hook(cub3d.win, 17, 1L << 19, &handle_key, &cub3d);
	mlx_loop_hook(cub3d.ptr, update, (void *)&cub3d);
	mlx_loop(cub3d.ptr);
    return (0);
}

	// int	x;

	// x = 0;
	// while (x < SW)
	// {
	// 	double	cameraX = 2 * x / SW - 1;
    // 	double rayDirX = cub3d->dir_x + cub3d->plane_x * cameraX;
    // 	double rayDirY = cub3d->dir_y + cub3d->plane_y * cameraX;
		
	// 	int	mapX = cub3d->player.p.x;
	// 	int	mapY = cub3d->player.p.y;

	// 	double	sideDistX;
	// 	double	sideDistY;

	// 	double deltaDistX;
	// 	double deltaDistY;
	// 	if (rayDirX == 0)
	// 		rayDirX = 1e30;
	// 	if (rayDirY == 0)
	// 		rayDirY = 1e30;
	// 	deltaDistX = fabs(1 / rayDirX);
	// 	deltaDistY = fabs(1 / rayDirY);

	// 	double	perpWallDist;
	// 	int		stepX;
	// 	int		stepY;
	// 	int		hit = 0;
	// 	int		side;

	// 	if(rayDirX < 0)
	// 	{
	// 		stepX = -1;
	// 		sideDistX = (cub3d->player.p.x - mapX) * deltaDistX;
	// 		}
	// 	else
	// 	{
	// 		stepX = 1;
	// 		sideDistX = (mapX + 1.0 - cub3d->player.p.x) * deltaDistX;
	// 	}
	// 	if(rayDirY < 0)
	// 	{
	// 		stepY = -1;
	// 		sideDistY = (cub3d->player.p.y - mapY) * deltaDistY;
	// 	}
	// 	else
	// 	{
	// 		stepY = 1;
	// 		sideDistY = (mapY + 1.0 - cub3d->player.p.y) * deltaDistY;
	// 	}

	// 	while(hit == 0)
	// 	{
	// 		if(sideDistX < sideDistY)
	// 		{
	// 			sideDistX += deltaDistX;
	// 			mapX += stepX;
	// 			side = 0;
	// 		}
	// 		else
	// 		{
	// 			sideDistY += deltaDistY;
	// 			mapY += stepY;
	// 			side = 1;
	// 		}
    //     	if(cub3d->map[mapX][mapY] > 0)
	// 			hit = 1;
	// 	}
    // 	if(side == 0)
	// 		perpWallDist = (sideDistX - deltaDistX);
    // 	else
	// 		perpWallDist = (sideDistY - deltaDistY);
    // 	int lineHeight = SH / perpWallDist;
	// 	int drawStart = -lineHeight / 2 + SH / 2;
	// 	if(drawStart < 0)
	// 		drawStart = 0;
	// 	int drawEnd = lineHeight / 2 + SH / 2;
	// 	if(drawEnd >= SH)
	// 		drawEnd = SH - 1;
	// 	unsigned int color;
    //   	if(cub3d->map[mapX][mapY] == '1')
	// 		color = ft_rgb2hex(135,206,250);
	// 	else if (cub3d->map[mapX][mapY] == '0')
	// 		color = cub3d->tex.f_color;
		
	// 	if (side == 1)
	// 	{
	// 		color = color / 2;
	// 	}

	// 	int	test = drawStart;
	// 	while (test <= drawEnd)
	// 	{
	// 		mlx_string_put(cub3d->ptr, cub3d->win, x, test, color, "test");
	// 		mlx_pixel_put(cub3d->ptr, cub3d->win, x, test, color);
	// 		test++;
	// 	}
	// 	// cub3d->oldtime = cub3d->time;
	// 	// cub3d->time = gettimeofday();
	// 	// double	frameTime = (cub3d->time - cub3d->oldtime) / 1000.0;
    // 	// print(1.0 / frameTime); //FPS counter
	// 	x++;
	// }


	// int	x;
	// int	hit;
	// int	side;

	// x = 0;
	// while (x < SW)
	// {
	// 	cub3d->camera_x = 2 * x / SW - 1;
	// 	cub3d->ray_dirx = cub3d->dir_x + cub3d->plane_x * cub3d->camera_x;
	// 	cub3d->ray_diry = cub3d->dir_y + cub3d->plane_y * cub3d->camera_x;
		
	// 	cub3d->mapX = cub3d->player.p.x;
	// 	cub3d->mapY = cub3d->player.p.y;

	// 	if (cub3d->ray_dirx == 0)
	// 		cub3d->ray_dirx = 1e30;
	// 	cub3d->deltaDistX = abs(1 / cub3d->ray_dirx);
	// 	if (cub3d->ray_diry == 0)
	// 		cub3d->ray_diry = 1e30;
	// 	cub3d->deltaDistY = abs(1 / cub3d->ray_diry);

	// 	hit = 0;

	// 	if (cub3d->ray_dirx < 0)
	// 	{
	// 		cub3d->step.x = -1;
	// 		cub3d->sideDistX = (cub3d->player.p.x - cub3d->mapX) * cub3d->deltaDistX;
	// 	}
	// 	else
	// 	{
	// 		cub3d->step.x = 1;
	// 		cub3d->sideDistX = (cub3d->mapX + 1.0 - cub3d->player.p.x) * cub3d->deltaDistX;
	// 	}
	// 	if (cub3d->ray_diry < 0)
	// 	{
	// 		cub3d->step.y = -1;
	// 		cub3d->sideDistY = (cub3d->player.p.y - cub3d->mapY) * cub3d->deltaDistY;
	// 	}
	// 	else
	// 	{
	// 		cub3d->step.y = 1;
	// 		cub3d->sideDistY = (cub3d->mapY + 1.0 - cub3d->player.p.y) * cub3d->deltaDistY;
	// 	}
		
	// 	while (hit == 0)
	// 	{
	// 		if(cub3d->sideDistX < cub3d->sideDistY)
	// 		{
	// 			cub3d->sideDistX += cub3d->deltaDistX;
	// 			cub3d->mapX += cub3d->step.x;
	// 			side = 0;
	// 		}
	// 		else
	// 		{
	// 			cub3d->sideDistY += cub3d->deltaDistY;
	// 			cub3d->mapY += cub3d->step.y;
	// 			side = 1;
	// 		}
	// 		if(cub3d->map[cub3d->mapX][cub3d->mapY] > 0)
	// 			hit = 1;
	// 	}
		
	// 	if (side == 0)
	// 		cub3d->perpWallDist = (cub3d->sideDistX - cub3d->deltaDistX);
	// 	else
	// 		cub3d->perpWallDist = (cub3d->sideDistY - cub3d->deltaDistY);

	// 	int lineHeight = (int)(SH / cub3d->perpWallDist);

	// 	int	pitch = 100;

	// 	int	drawStart = -lineHeight / 2 + SH / 2 + pitch;
	// 	if (drawStart < 0)
	// 		drawStart = 0;
	// 	int drawEnd = lineHeight / 2 + SH / 2 + pitch;
	// 	if (drawEnd >= SH)
	// 		drawEnd = SH - 1;

	// 	int	texNum = cub3d->map[cub3d->mapX][cub3d->mapY] - 1;

	// 	double	wallX;
	// 	if (side == 0)
	// 		wallX = cub3d->player.p.y + cub3d->perpWallDist * cub3d->ray_diry;
	// 	else
	// 		wallX = cub3d->player.p.x + cub3d->perpWallDist * cub3d->ray_dirx; 
	// 	wallX -= floor((wallX));

	// 	int	texX = wallX * TEXW;
	// 	if (side == 0 && cub3d->ray_dirx > 0)
	// 		texX = TEXW - texX - 1;
	// 	if (side == 1 && cub3d->ray_diry < 0)
	// 		texX = TEXW - texX - 1;

	// 	double	step = 1.0 * TEXH / lineHeight;

	// 	double	texPos = (drawStart - pitch - SH / 2 + lineHeight / 2) * step;
	// 	int y = drawStart;
	// 	while (y < drawEnd)
	// 	{
	// 		int	texY = (int)texPos & (TEXH - 1);
	// 		texPos += step;
	// 		unsigned int color = cub3d->tex.ea[TEXH * texY + texX];
	// 		y++;
	// 	}
		

	// 	x++;
	// }