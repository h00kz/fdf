#include "../include/fdf.h"
#include <math.h>

void	ft_isometric(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}

void	ft_bresenham(t_point start, t_point end, t_fdf *data)
{
	t_point	step;
	int		max;

	start.z = data->z_matrix[(int)start.y][(int)start.x];
	end.z = data->z_matrix[(int)end.y][(int)end.x];	
	ft_zoom(&start, &end, data->zoom);
	ft_altitude(&start, &end, data->altitude);
	if (start.z > 0 || end.z > 0)
		data->color = ft_rgb_to_int(200, 0, 0);
	else if (start.z < 0 || end.z < 0)
		data->color = ft_rgb_to_int(0, 0, 200);
	else
		data->color = ft_rgb_to_int(255, 255, 255);
	ft_isometric(&start, data->angle);
	ft_isometric(&end, data->angle);
	step.x = (end.x - start.x);
	step.y = (end.y - start.y);
	ft_shift(&start, &end, data->x_shift, data->y_shift);
	max = fmax(fabs(step.x), fabs(step.y)); 
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(data->mlx, data->win, (int)start.x, (int)start.y, data->color);
		start.x += step.x;
		start.y += step.y;
	}
}

void	ft_draw(t_fdf *data)
{
	t_point start;
	t_point	end;

	start.y = 0;
	while (start.y < data->height)
	{
		start.x = 0;
		while (start.x < data->width)
		{
			if (start.x < data->width - 1)
			{
				end.y = start.y;
				end.x = start.x + 1;
				ft_bresenham(start, end, data);
			}
			if (start.y < data->height - 1)
			{
				end.x = start.x;
				end.y = start.y + 1;
				ft_bresenham(start, end, data);
			}
			start.x++;
		}
		start.y++;
	}
}
