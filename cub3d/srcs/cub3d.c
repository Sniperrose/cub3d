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

	x = 0;
	while (x < cub3d->map_w)
	{
		cub3d->camera_x = 2 * x / cub3d->map_w - 1;
		cub3d->ray_dirx = cub3d->dir_x + cub3d->plane_x * cub3d->camera_x;
		cub3d->ray_diry = cub3d->dir_y + cub3d->plane_y * cub3d->camera_x;
		
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
	mlx_loop_hook(cub3d.ptr, update, (void *)&cub3d);
	mlx_loop(cub3d.ptr);
    return (0);
}