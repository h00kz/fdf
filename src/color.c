#include "../include/fdf.h"

int	ft_rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}
