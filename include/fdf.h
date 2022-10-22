#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <stdio.h> // A DEGAGER

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 1024

typedef enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_SPACE = 32,
	KEY_ESC = 65307,
	KEY_Z = 122,
	KEY_X = 120
}			t_keys;

typedef struct s_color
{
	int a;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
}				t_point;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		color;
	int		**z_matrix;
	int		zoom;
	double	x_shift;
	double	y_shift;
	double	angle;
	double	altitude;
}				t_fdf;

void	ft_zoom(t_point *start, t_point *end, int zoom);
void	ft_shift(t_point *start, t_point *end, double x, double y);
void	ft_altitude(t_point *start, t_point *end, double altitude);
void	ft_isometric(t_point *point, double angle);
void	ft_bresenham(t_point start, t_point end, t_fdf *data);
void	ft_draw(t_fdf *data);

int		ft_mouse_handler(int button, int x, int y, t_fdf *fdf);
int		ft_key_handler(int keycode, t_fdf *fdf);

void	ft_fill_matrix(int *z_point, char *line);
int		ft_get_width(const char *file_name);
int		ft_get_height(const char *file_name);
void	ft_read_map(const char *file_name, t_fdf *data);
void	ft_free_matrix(int **matrix);
void	ft_error(int **mat);
int		ft_rgb_to_int(int r, int g, int b);
#endif
