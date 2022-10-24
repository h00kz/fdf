/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:18:15 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/21 16:25:18 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		ft_close(fdf);
		exit(0);
	}
	if (keycode == 61) // +
		fdf->altitude += 0.05;
	if (keycode == 45) // -
		fdf->altitude -= 0.05;
	if (keycode == 65364) // left arrow
		fdf->alpha += 0.01;
	if (keycode == 65362) // right arrow
		fdf->alpha -= 0.01;
	if (keycode == 65361) // up arrow
		fdf->beta += 0.01;
	if (keycode == 65363) // down arrow
		fdf->beta -= 0.01;
	if (keycode == KEY_W)
		fdf->shift.y -= 1;
	if (keycode == KEY_S)
		fdf->shift.y += 1;
	if (keycode == KEY_D)
		fdf->shift.x += 1;
	if (keycode == KEY_A)
		fdf->shift.x -= 2;
	if (keycode == 105)
		fdf->isometric = -fdf->isometric;
	if (keycode == KEY_SPACE)
		ft_init_fdf(fdf);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	ft_print_menu(fdf, 0xffffff);
	printf("key:%d\t iso:%d\n", keycode, fdf->isometric);
	return (0);
}
