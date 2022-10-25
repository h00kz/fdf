/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:25:03 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 15:46:06 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_dda_aglo(t_point start, t_point end, t_fdf *data)
{
	t_point	step;
	int		max;

	start.z = data->z_matrix[(int)start.y][(int)start.x];
	end.z = data->z_matrix[(int)end.y][(int)end.x];
	ft_zoom(&start, &end, ft_clamp(data->zoom, 2, 30));
	ft_altitude(&start, &end, data->altitude);
	if (data->palette == 2)
		ft_set_color_red(start, end, &(data->color));
	else
		ft_set_color_wild(start, end, &(data->color));
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
	ft_process_step(&step, start, end, &max);
	ft_shift(&start, &end, data->shift);
	ft_put_segment_pix(&start, end, step, data);
}

void	ft_put_segment_pix(t_point *start, t_point end, \
						t_point step, t_fdf *fdf)
{
	while ((int)(start->x - end.x) || (int)(start->y - end.y))
	{
		my_mlx_pixel_put(&fdf->img, start->x, start->y, fdf->color);
		start->x += step.x;
		start->y += step.y;
	}
}

void	ft_process_step(t_point *step, t_point start, t_point end, int *max)
{
	step->x = (end.x - start.x);
	step->y = (end.y - start.y);
	*max = (int)fmax(fabs(step->x), fabs(step->y));
	step->x /= *max;
	step->y /= *max;
}
