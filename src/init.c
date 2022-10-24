#include "../include/fdf.h"

void	ft_init_fdf(t_fdf *fdf)
{
	if (!fdf->mlx || !fdf->win || !fdf->img.img)
	{
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
		fdf->img.img = mlx_new_image(fdf->mlx, WINDOW_WIDTH * 4, WINDOW_HEIGHT * 4);
		fdf->img.addr = mlx_get_data_addr(fdf->img.img, &(fdf->img.bits_per_pixel),
				&(fdf->img.line_length), &(fdf->img.endian));
	}
	fdf->zoom = 15;
	fdf->angle = 0.823599;
	fdf->altitude = 0.05;
	fdf->alpha = 5.25;
	fdf->beta = 12.0;
	fdf->shift.x = WINDOW_WIDTH / 2;
	fdf->shift.y = 340;
	fdf->isometric = 1;
}
