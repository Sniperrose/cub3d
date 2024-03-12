#include "../include/cub3d.h"

int	handle_key(t_cub3d *game)
{
	exit (ft_freegame(game, "Exit: RED CROSS\n"));
}

int	handle_keypress(int keysym, t_cub3d *game)
{
	// t_vector	pos;
	int			i;

	i = 0;
    //movement here
	if (keysym == XK_Escape)
		exit (ft_freegame(game, "Exit: ESC\n"));
	if (i == -1)
		exit (ft_freegame(game, "Exit: Game end!\n"));
	return (i);
}

void	*display_game(t_cub3d *game)
{
    t_vec   test;

    test.x = 0;
    test.y = 0;
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.ea.pointer, 10, 10);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.ea.pointer, 74, 10);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.ea.pointer, 138, 10);

    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.no.pointer, 10, 84);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.no.pointer, 74, 84);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.no.pointer, 138, 84);

    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.so.pointer, 10, 158);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.so.pointer, 74, 158);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.so.pointer, 138, 158);

    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.we.pointer, 10, 232);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.we.pointer, 74, 232);
    mlx_put_image_to_window(game->ptr, game->win,
					game->tex.we.pointer, 138, 232);

	return (game->ptr);
}

void	render(t_cub3d game)
{
	display_game(&game);
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