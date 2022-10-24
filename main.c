/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:08:35 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 15:58:43 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_close(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	ft_free_matrix(fdf->z_matrix);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	(void)ac;
	fdf = malloc(sizeof(t_fdf) * 1);
	if (!fdf)
		return (1);
	if (ac == 2)
	{
		ft_init_fdf(fdf);
		ft_read_map(av[1], fdf);
		ft_draw(fdf);
		mlx_hook(fdf->win, 2, 1L, &ft_key_handler, fdf);
		mlx_hook(fdf->win, 17, (1L << 17), &ft_close, fdf);
		mlx_hook(fdf->win, 4, (1L << 2), &ft_mouse_handler, fdf);
		mlx_loop(fdf->mlx);
	}
	printf("Usage: ./fdf map_name.fdf\n");
	ft_close(fdf);
	return (0);
}
