/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:56:16 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 15:59:30 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	start->z *= altitude / 20;
	end->z *= altitude / 20;
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	{
		dst = data->addr + (y * data->line_length + \
							x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
