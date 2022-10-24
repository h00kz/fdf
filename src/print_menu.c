/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:21:35 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 17:07:06 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_print_menu(t_fdf *fdf, unsigned int c)
{
	char	*seekers;
	int		x;
	int		y;

	x = 10;
	seekers = "SEEKERS FTW";
	while (x <= 270)
	{
		y = 18;
		while (y < WINDOW_WIDTH - 56)
		{
			mlx_string_put(fdf->mlx, fdf->win, x, \
					y, 0xb02f1e, \
					seekers);
			y += 15;
		}
		x += 70;
	}
	x = 20;
	mlx_string_put(fdf->mlx, fdf->win, x, 50, c, \
			"West, East, North, South : [A] [D] [W] [S]");
	mlx_string_put(fdf->mlx, fdf->win, x, 100, c, \
			"Zoom In / Out : [SCROLL UP] / [SCROLL DOWN]");
	mlx_string_put(fdf->mlx, fdf->win, x, 150, c, \
			"Increase / Decrease Altitude : [+] / [-]");
	mlx_string_put(fdf->mlx, fdf->win, x, 200, c, \
			"Rotate around axis : [<-] [->] [^] [v]");
	mlx_string_put(fdf->mlx, fdf->win, x, 250, c, \
			"SPACE : Reset map to initial position");
	mlx_string_put(fdf->mlx, fdf->win, x + 100, WINDOW_HEIGHT - 100, c, \
			"Exit : [ESCAPE]");
}
