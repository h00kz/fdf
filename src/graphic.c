#include "../include/fdf.h"

void	ft_isometric(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}

void	ft_rotation_matrix(t_point	*point, t_fdf *fdf)
{
	double	x;
	double	y;
	double	z;

	x = (double)point->x;
	y = (double)point->y;
	z = (double)point->z;
	point->y = (int)round((y * cos(fdf->alpha)) + (z * sin(fdf->alpha)));
	point->z = (int)round((-y * sin(fdf->alpha)) + (z * cos(fdf->alpha)));
	z = (double)point->z;
	point->x = (int)round((x * cos(fdf->beta)) + (z * sin(fdf->beta)));
	point->z = (int)round((-x * sin(fdf->beta)) + (z * cos(fdf->beta)));
}

void	ft_bresenham(t_point start, t_point end, t_fdf *data)
{
	t_point	step;
	int		max;

	start.z = data->z_matrix[(int)start.y][(int)start.x];
	end.z = data->z_matrix[(int)end.y][(int)end.x];
	ft_zoom(&start, &end, ft_clamp(data->zoom, 2, 24));
	ft_altitude(&start, &end, ft_clamp(data->altitude, -0.25, 0.25));
	ft_set_color(start, end, &(data->color));
	if (data->isometric > 0)
	{
		ft_isometric(&start, data->angle);
		ft_isometric(&end, data->angle);   
	}
	else
	{
		ft_rotation_matrix(&start, data);	
		ft_rotation_matrix(&end, data);	
	}
	step.x = (end.x - start.x);
	step.y = (end.y - start.y);
	ft_shift(&start, &end, data->shift);
	max = (int)fmax(fabs(step.x), fabs(step.y)); 
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		my_mlx_pixel_put(&data->img, start.x, start.y, data->color);
		start.x += step.x;
		start.y += step.y;
	}
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void    ft_set_color(t_point start, t_point end, int *data_color)
{
	if (start.z > 0 || end.z > 0)
		*data_color = ft_rgb_to_int(ft_clamp(255 - start.z * 50, 60, 255),
				ft_clamp(255 - start.z * 10, 110, 255),
				ft_clamp(abs(start.z), 0, 255));
	else if (start.z < 0 || end.z < 0)
		*data_color = ft_rgb_to_int(30,
				ft_clamp(255 - abs(end.z) * 8, 30, 215),
				ft_clamp(255 - abs(end.z) * 4, 30, 255));
	else
		*data_color = ft_rgb_to_int(0, 215, 255);
}
