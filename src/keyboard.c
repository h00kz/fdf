/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:18:15 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 16:25:07 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		ft_close(fdf);
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
		fdf->shift.x -= 1;
	if (keycode == 105)
		fdf->isometric = -fdf->isometric;
	if (keycode == KEY_SPACE)
		ft_init_fdf(fdf);
	if (keycode == KEY_X)
	{
		if (fdf->palette == 1)
			fdf->palette = 2;
		else
			fdf->palette = 1;
	}
	ft_draw(fdf);
	return (0);
}
