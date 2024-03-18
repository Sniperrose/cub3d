#include "../include/cub3d.h"

int	handle_key(t_cub3d *cub3d)
{
	exit (ft_freegame(cub3d, "Exit: RED CROSS\n"));
}

int	handle_keypress(int keysym, t_cub3d *cub3d)
{
	// t_vector	pos;
	int			i;

	i = 0;
    //movement here
	if (keysym == XK_Escape)
		exit (ft_freegame(cub3d, "Exit: ESC\n"));
	return (i);
}

void	*display_game(t_cub3d *cub3d)
{
	int	x;
	int	hit;
	int	side;

	x = 0;
	while (x < SW)
	{
		cub3d->camera_x = 2 * x / SW - 1;
		cub3d->ray_dirx = cub3d->dir_x + cub3d->plane_x * cub3d->camera_x;
		cub3d->ray_diry = cub3d->dir_y + cub3d->plane_y * cub3d->camera_x;
		
		cub3d->mapX = cub3d->player.p.x;
		cub3d->mapY = cub3d->player.p.y;

		if (cub3d->ray_dirx == 0)
			cub3d->ray_dirx = 1e30;
		cub3d->deltaDistX = abs(1 / cub3d->ray_dirx);
		if (cub3d->ray_diry == 0)
			cub3d->ray_diry = 1e30;
		cub3d->deltaDistY = abs(1 / cub3d->ray_diry);

		hit = 0;

		if (cub3d->ray_dirx < 0)
		{
			cub3d->step.x = -1;
			cub3d->sideDistX = (cub3d->player.p.x - cub3d->mapX) * cub3d->deltaDistX;
		}
		else
		{
			cub3d->step.x = 1;
			cub3d->sideDistX = (cub3d->mapX + 1.0 - cub3d->player.p.x) * cub3d->deltaDistX;
		}
		if (cub3d->ray_diry < 0)
		{
			cub3d->step.y = -1;
			cub3d->sideDistY = (cub3d->player.p.y - cub3d->mapY) * cub3d->deltaDistY;
		}
		else
		{
			cub3d->step.y = 1;
			cub3d->sideDistY = (cub3d->mapY + 1.0 - cub3d->player.p.y) * cub3d->deltaDistY;
		}
		
		while (hit == 0)
		{
			if(cub3d->sideDistX < cub3d->sideDistY)
			{
				cub3d->sideDistX += cub3d->deltaDistX;
				cub3d->mapX += cub3d->step.x;
				side = 0;
			}
			else
			{
				cub3d->sideDistY += cub3d->deltaDistY;
				cub3d->mapY += cub3d->step.y;
				side = 1;
			}
			if(cub3d->map[cub3d->mapX][cub3d->mapY] > 0)
				hit = 1;
		}
		
		if (side == 0)
			cub3d->perpWallDist = (cub3d->sideDistX - cub3d->deltaDistX);
		else
			cub3d->perpWallDist = (cub3d->sideDistY - cub3d->deltaDistY);

		int lineHeight = (int)(SH / cub3d->perpWallDist);

		int	pitch = 100;

		int	drawStart = -lineHeight / 2 + SH / 2 + pitch;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SH / 2 + pitch;
		if (drawEnd >= SH)
			drawEnd = SH - 1;

		int	texNum = cub3d->map[cub3d->mapX][cub3d->mapY] - 1;

		double	wallX;
		if (side == 0)
			wallX = cub3d->player.p.y + cub3d->perpWallDist * cub3d->ray_diry;
		else
			wallX = cub3d->player.p.x + cub3d->perpWallDist * cub3d->ray_dirx; 
		wallX -= floor((wallX));

		int	texX = wallX * TEXW;
		if (side == 0 && cub3d->ray_dirx > 0)
			texX = TEXW - texX - 1;
		if (side == 1 && cub3d->ray_diry < 0)
			texX = TEXW - texX - 1;

		double	step = 1.0 * TEXH / lineHeight;

		double	texPos = (drawStart - pitch - SH / 2 + lineHeight / 2) * step;
		int y = drawStart;
		while (y < drawEnd)
		{
			int	texY = (int)texPos & (TEXH - 1);
			texPos += step;
			color = texture()
			y++;
		}
		

		x++;
	}
	return (cub3d->ptr);
}

void	render(t_cub3d cub3d)
{
	display_game(&cub3d);
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
	// mlx_loop_hook(cub3d.ptr, update, (void *)&cub3d);
	mlx_loop(cub3d.ptr);
    return (0);
}