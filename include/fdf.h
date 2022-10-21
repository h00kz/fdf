#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

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
	KEY_F = 0,
	KEY_J = 0,
	KEY_K = 0
}			t_keys;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		**z_matrix;
	double	zoom;
	double	x_shift;
	double	y_shift;
}				t_fdf;

float	ft_max(float a, float b);
float	ft_abs(float a, float b);

int		ft_key_handler(int keycode, t_fdf *fdf);

void	ft_fill_matrix(int *z_point, char *line);
int		ft_get_width(const char *file_name);
int		ft_get_height(const char *file_name);
void	ft_read_map(const char *file_name, t_fdf *data);
void	ft_free_matrix(int **matrix);
void	ft_error(int **mat);

#endif
