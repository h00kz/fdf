/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:08:35 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/21 16:50:12 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>

// ---------------------- FORDEBUG ----------------------
void	print_ma(int **ma, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			printf("%3d", ma[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
// ------------------------------------------------------

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	(void)ac;
	fdf = malloc(sizeof(t_fdf) * 1);
	if (!fdf)
		return (0);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	fdf->zoom = 20;
	fdf->angle = 0.80;
	fdf->altitude = 1;
	fdf->x_shift = 200;
	fdf->y_shift = 200;
	ft_read_map(av[1], fdf);
	print_ma(fdf->z_matrix, fdf->height, fdf->width);
	ft_draw(fdf);
	//mlx_key_hook(fdf->win, ft_key_handler, fdf);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, &ft_key_handler, fdf);
	mlx_hook(fdf->win, ButtonPress, ButtonPressMask, &ft_mouse_handler, fdf);
	mlx_loop(fdf->mlx);
	ft_free_matrix(fdf->z_matrix);
	free(fdf);
	return (0);
}
