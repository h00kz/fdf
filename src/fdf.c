#include "fdf.h"
#include <stdlib.h>

char	*get_next_line_tmp(int fd)
{
	char *s = malloc(10000), *c = s;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	return (c > s) ? (*c = 0, s) : (free(s), NULL);
}

int	ft_get_height(const char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error();
	height = 0;
	while (line = get_next_line(fd))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	ft_error()
{
}

int	ft_get_width(const char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line_tmp(fd);
	//printf("%s", line);
	width = ft_count_word(' ', line);
	free(line);
	close(fd);
	return (width);
}

void	ft_fill_matrix(int *z_point, char *line)
{
	char	**digits;
	int		i;

	digits = ft_split(line, ' ');
	i = 0;
	while (digits[i])
	{
		z_point[i] = ft_atoi(digits[i]);
		free(digits[i]);
		i++;
	}
	free(digits);
}

void	ft_read_map(const char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	data->z_matrix = malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i] = malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (line = get_next_line(fd))
	{
		ft_fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
