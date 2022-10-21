#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_keys
{
	KEY_W = 0,
	KEY_A = 0,
	KEY_S = 0,
	KEY_D = 0,
	KEY_SPACE = 0,
	KEY_ESC = 0,
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

void	ft_fill_matrix(int *z_point, char *line);
int		ft_get_width(const char *file_name);
int		ft_get_height(const char *file_name);
void	ft_read_map(const char *file_name, t_fdf *data);

void	ft_error();

#endif
