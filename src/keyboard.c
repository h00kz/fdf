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

int	ft_mouse_handler(int button, int x, int y, t_fdf *fdf)
{
	if (button == 4)
		fdf->zoom += 2;
	if (button == 5)
		fdf->zoom -= 2;
	printf("BUTTON: %d\t x: %d , y: %d\n", button, x, y);
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_draw(fdf);
	return (0);
}

int	ft_key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		ft_free_matrix(fdf->z_matrix);
		exit(0);
	}

	if (keycode == 65364)
		fdf->altitude += 0.3;
	if (keycode == 65362)
		fdf->altitude -= 0.3;
	if (keycode == 65361)
		fdf->angle += 0.05;
	if (keycode == 65363)
		fdf->angle -= 0.05;
	if (keycode == KEY_W)
		fdf->y_shift -= 2;
	if (keycode == KEY_S)
		fdf->y_shift += 2;
	if (keycode == KEY_A)
		fdf->x_shift += 2;
	if (keycode == KEY_D)
		fdf->x_shift -= 2;
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_draw(fdf);
	//printf("%d\n", keycode);
	return (0);
}
