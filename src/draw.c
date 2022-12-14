#include "../include/fdf.h"

void	ft_draw_fdf(t_fdf *data)
{
	t_point	start;
	t_point	end;

	start.y = 0;
	while (start.y < data->height)
	{
		start.x = 0;
		while (start.x < data->width)
		{
			if (start.x < data->width - 1)
			{
				end.y = start.y;
				end.x = start.x + 1;
				ft_dda_aglo(start, end, data);
			}
			if (start.y < data->height - 1)
			{
				end.x = start.x;
				end.y = start.y + 1;
				ft_dda_aglo(start, end, data);
			}
			start.x++;
		}
		start.y++;
	}
}

void	ft_draw(t_fdf *fdf)
{
	ft_draw_background(&(fdf->img), ft_rgb_to_int(25, 25, 25));
	ft_draw_fdf(fdf);
	ft_draw_ui(&(fdf->img), (t_rect){5, 5, \
									(WINDOW_WIDTH / 6) - 10, \
									WINDOW_HEIGHT - 10, \
									ft_rgb_to_int(150, 5, 30)});
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	ft_print_menu(fdf, 0x9f9f9f);
}

void	ft_draw_ui(t_image *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			my_mlx_pixel_put(img, j, i, rect.color);
			j++;
		}
		i++;
	}
}

void	ft_draw_background(t_image *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}
