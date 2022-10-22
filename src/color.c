#include "../include/fdf.h"

int	ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
