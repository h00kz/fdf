/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:28:31 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:34 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_get_height(const char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_error(NULL);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_get_width(const char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_word_count(' ', line);
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

void	ft_free_matrix(int	**matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
	while (i < data->height)
	{
		data->z_matrix[i] = malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	data->z_matrix[i] = NULL;
}
