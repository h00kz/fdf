/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:17:30 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/12 10:52:46 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	strs_len;
	size_t	i;
	char	*str;

	i = 0;
	strs_len = ft_strlen_g(s1) + ft_strlen_g(s2);
	str = ft_calloc(strs_len + 1, sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	i = 0;
	while (s2[i] && i < strs_len)
	{
		str[i + ft_strlen_g(s1)] = s2[i];
		++i;
	}
	free(s1);
	return (str);
}

int	ft_found_nl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem_block;
	size_t			i;

	i = 0;
	mem_block = malloc(sizeof(unsigned char) * (nmemb * size));
	if (!mem_block)
		return (NULL);
	while (i < (nmemb * size))
	{
		mem_block[i] = 0;
		i++;
	}
	return (mem_block);
}

int	ft_strlen_g(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}
