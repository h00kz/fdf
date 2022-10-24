#include "../include/fdf.h"

void    ft_print_menu(t_fdf *fdf, unsigned int c)
{
	short	x;

	x = 20;
	mlx_string_put(fdf->mlx, fdf->win, x, 50, c,
			"West, East, North, South : [A] [D] [W] [S]");
	mlx_string_put(fdf->mlx, fdf->win, x, 100, c, 
			"Zoom In / Out : [SCROLL UP] / [SCROLL DOWN]");
	mlx_string_put(fdf->mlx, fdf->win, x, 150, c,
			"Increase / Decrease Altitude : [+] / [-]");
	mlx_string_put(fdf->mlx, fdf->win, x, 200, c,
			"Rotate around axis : [<-] [->] [^] [v]");
	mlx_string_put(fdf->mlx, fdf->win, x, 250, c,
			"SPACE : Reset map to initial position");
	mlx_string_put(fdf->mlx, fdf->win, x, WINDOW_HEIGHT - 100, c,
			"Exit : [ESCAPE]");
}
