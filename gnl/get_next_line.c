/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:17:10 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/14 10:31:29 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *s_save)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		s_save = ft_strjoin_free(s_save, buffer);
		if (ft_found_nl(s_save))
			break ;
	}
	free(buffer);
	return (s_save);
}

void	ft_get_bfr_nl(char *s_save, char **line)
{
	int		i;

	if (!s_save)
		return ;
	i = 0;
	while (s_save[i] != '\n' && s_save[i])
		i++;
	*line = ft_calloc(i + 2, sizeof(char));
	if (!(*line))
		return ;
	i = 0;
	while (s_save[i] != '\n' && s_save[i])
	{
		(*line)[i] = s_save[i];
		i++;
	}
	if (s_save[i] && s_save[i] == '\n')
		(*line)[i] = s_save[i];
}

char	*ft_get_aft_nl(char *s_save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!ft_found_nl(s_save))
	{
		free(s_save);
		return (NULL);
	}
	while (s_save[i] != '\n' && s_save[i])
		i++;
	i++;
	tmp = ft_calloc((ft_strlen_nl(s_save) - i) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (s_save[i + j])
	{
		tmp[j] = s_save[j + i];
		j++;
	}
	free(s_save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*f_line;
	static char	*s_save = NULL;

	line = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	f_line = ft_get_line(fd, s_save);
	if (!f_line)
		return (NULL);
	if (!(*f_line))
	{
		free(f_line);
		return (NULL);
	}
	ft_get_bfr_nl(f_line, &line);
	s_save = ft_get_aft_nl(f_line);
	return (line);
}
