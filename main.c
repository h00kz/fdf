#include "src/fdf.h"
#include <stdlib.h>

int		ft_key_handler(int keycode, void *params)
{
	printf("%d\n", keycode);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf) * 1);
	if (!fdf)
		return (0);
	ft_read_map(av[1], fdf);

	int i;
	int j;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			printf("%3d", fdf->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(fdf);
	return (0);
}
