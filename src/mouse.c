#include "../include/fdf.h"

int	ft_mouse_handler(int button, int x, int y, t_fdf *fdf)
{
	if (button == 4)
		fdf->zoom += 1;
	if (button == 5)
		fdf->zoom -= 1;
	printf("BUTTON: %d\t x: %d , y: %d\n", button, x, y);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	ft_print_menu(fdf, 0xffffff);
	return (0);
}
