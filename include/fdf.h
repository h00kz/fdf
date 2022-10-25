#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h> // A DEGAGER

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1000

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}				t_rect;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

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

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_point;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		color;
	int		**z_matrix;
	double	zoom;
	t_point	shift;
	double	angle;
	double	altitude;
	double	alpha;
	double	beta;
	int		isometric;
	t_image	img;
	int		palette;
}				t_fdf;

void	ft_process_step(t_point *step, t_point start, t_point end, int *max);
void	ft_put_segment_pix(t_point *start, t_point end, \
							t_point step, t_fdf *fdf);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
float	ft_clamp(float value, float min, float max);
int		ft_lerp(int a, int b, int f);
void	ft_zoom(t_point *start, t_point *end, int zoom);
void	ft_shift(t_point *start, t_point *end, t_point shift);
void	ft_altitude(t_point *start, t_point *end, double altitude);
void	ft_isometric(t_point *point, double angle);
void	ft_dda_aglo(t_point start, t_point end, t_fdf *data);
void	ft_set_color_wild(t_point start, t_point end, int *data_color);
void	ft_set_color_red(t_point start, t_point end, int *data_color);
void	ft_draw_background(t_image *img, int color);
void	ft_draw_fdf(t_fdf *fdf);
void	ft_draw_ui(t_image *img, t_rect rect);
void	ft_draw(t_fdf *fdf);
void	ft_rotation_matrix(t_point	*point, t_fdf *fdf);

int		ft_mouse_handler(int button, int x, int y, t_fdf *fdf);
int		ft_key_handler(int keycode, t_fdf *fdf);

void	ft_init_fdf(t_fdf *fdf);
void	ft_fill_matrix(int *z_point, char *line);
int		ft_get_width(const char *file_name);
int		ft_get_height(const char *file_name);
void	ft_read_map(const char *file_name, t_fdf *data);
void	ft_free_matrix(int **matrix);
void	ft_error(int **mat);
int		ft_close(t_fdf *fdf);
int		ft_rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
void	ft_print_menu(t_fdf *fdf, unsigned int c);
#endif
