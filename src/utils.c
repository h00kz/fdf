#include "../include/fdf.h"

float	ft_clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}

int ft_lerp(int a, int b, int f)
{
	return a * (1.0 - f) + (b * f);
}

void	ft_zoom(t_point *start, t_point *end, int zoom)
{
	start->x *= zoom;
	start->y *= zoom;
	start->z *= zoom;
	end->x *= zoom;
	end->y *= zoom;
	end->z *= zoom;
}

void	ft_shift(t_point *start, t_point *end, t_point shift)
{
	start->x += shift.x;
	start->y += shift.y;
	end->x += shift.x;
	end->y += shift.y;
}

void	ft_altitude(t_point *start, t_point *end, double altitude)
{
	start->z *= altitude / 2.0;
	end->z *= altitude / 2.0;
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_close(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	ft_free_matrix(fdf->z_matrix);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
}
