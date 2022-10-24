/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:23:25 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 14:50:16 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_init_fdf(t_fdf *fdf)
{
	if (!fdf->mlx || !fdf->win || !fdf->img.img)
	{
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, \
				WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
		fdf->img.img = mlx_new_image(fdf->mlx, \
									WINDOW_WIDTH, \
									WINDOW_HEIGHT);
		fdf->img.addr = mlx_get_data_addr(fdf->img.img, \
										&(fdf->img.bits_per_pixel), \
										&(fdf->img.line_length), \
										&(fdf->img.endian));
	}
	fdf->zoom = 15;
	fdf->angle = 0.823599;
	fdf->altitude = 0.5;
	fdf->alpha = 5.25;
	fdf->beta = 12.0;
	fdf->shift.x = WINDOW_WIDTH / 2;
	fdf->shift.y = 340;
	fdf->isometric = 1;
}
