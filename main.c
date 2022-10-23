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

int ft_close_window(t_fdf *fdf)
{
    ft_close(fdf);
	exit (0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	(void)ac;
	fdf = malloc(sizeof(t_fdf) * 1);
	if (!fdf)
		return (1);
	ft_init_fdf(fdf);
	ft_read_map(av[1], fdf);
	//print_ma(fdf->z_matrix, fdf->height, fdf->width);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	ft_print_menu(fdf, 0xffffff);
	mlx_hook(fdf->win, 2, (1L<<0), &ft_key_handler, fdf);
	mlx_hook(fdf->win, 17, (1L << 17), &ft_close_window, fdf);
	mlx_hook(fdf->win, 4, (1L<<2), &ft_mouse_handler, fdf);
	mlx_loop(fdf->mlx);
	ft_close(fdf);
	return (0);
}
