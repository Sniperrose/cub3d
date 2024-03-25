#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>  
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define SW 640
# define SH 480
# define TEXW 64
# define TEXH 64
# define MAPW 24
# define MAPH 24

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_image
{
	void	*pointer;
	t_vec	size;
}		t_image;

typedef struct	s_texure
{
	t_image	no;
	t_image	so;
	t_image	we;
	t_image	ea;
	int		f_color;
	int		c_color;
}	t_texure;

typedef struct	s_minimap
{
	t_image	wall;
	t_image	icon;
	t_image	space;
}	t_minimap;


typedef	struct	s_player
{
	t_vec	p;
	char	start_dir;
}	t_player;

typedef struct s_dir
{
	t_vec	front;
	t_vec	left;
	t_vec	right;
	t_vec	back;
}	t_dir;

typedef struct s_cub3d
{
	void		*ptr;
	void		*win;
    t_texure	tex;
    char		**map;
	t_player	player;
	t_minimap	mini;

	t_dir		dir;
	double		time;
	double		oldtime;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;

}	t_cub3d;

//libft NORM OK
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *all, char const *argv);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(char c);
int		ft_atoi(const char *nptr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
//GNL
char	*get_next_line(int fd);
char	*ft_read(int fd, char **gstr);
char	*return_line(int rc, char **gstr);
char	*ft_sep_line(char **gstr);
//utils	done NORM OK
int		ft_error(char *str);
int		ft_iswhitespace(char c);
size_t	ft_countsep(const char *all, char sep);
int		ft_str_is_printable(char *str);
//mlx_utils
t_image	ft_new_sprite(void *ptr, char *path);
int		ft_freegame(t_cub3d *cub3d, char *str);
//read_mapfile done NORM OK
int		check_map_ext(char *str);
size_t  ft_mapfile_size(char *src);
char    **ft_copy_mapfile(int fd, size_t size);
char	**ft_readmapfile(char *src);
//init_texure DONE NORM_OK
int		ft_rgb2hex(int r, int g, int b);
int		ft_getcolorval(const char *str);
char	*ft_getpath(const char *str);
int		ft_init_texure(char *path, t_cub3d *data);
int		ft_check_and_init_elems(t_cub3d *cub3d, char **tmp);
//init_map DONE NORM OK
int		ft_initmap(t_cub3d *cub3d, char **tmp);
char	**ft_getmap(char **tmp, int size);
int		ft_ismappart(char *str);
//init_map2 DONE NORM OK
int		ft_mapfill(char **map, int i, int j, char c);
int		ft_leak(char **map, int i, int j);
int		ft_checkwall(char **tmp, size_t size, char c);
int		ft_validmap(char **map, char c);
int		ft_check_map(char **map, t_cub3d *cub3d);
//free
void    ft_free(char **src);
void	ft_free_texure(t_cub3d *cub3d);
//init_envs
void	ft_set_null(t_cub3d *data);
int		ft_initdata(t_cub3d *cub3d, char **tmp);
//cub3d
int ft_raycast(t_cub3d cub3d);

#endif
