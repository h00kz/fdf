/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:17:23 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/12 10:49:35 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_strlen_nl(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_get_line(int fd, char *s_save);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_found_nl(const char *s);
void	ft_get_bfr_nl(char *s_save, char **line);
char	*ft_get_aft_nl(char *s_save);

#endif
