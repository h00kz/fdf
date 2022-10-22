#include "../include/fdf.h"

void	ft_zoom(t_point *start, t_point *end, int zoom)
{
	start->x *= zoom;
	start->y *= zoom;
	end->x *= zoom;
	end->y *= zoom;
}

void	ft_shift(t_point *start, t_point *end, double x, double y)
{
	start->x += x;
	start->y += y;
	end->x += x;
	end->y += y;
}

void	ft_altitude(t_point *start, t_point *end, double altitude)
{
	start->z *= altitude;
	end->z *= altitude;
}
