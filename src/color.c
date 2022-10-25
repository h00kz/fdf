/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:26:05 by jlarrieu          #+#    #+#             */
/*   Updated: 2022/10/24 15:35:23 by jlarrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

void	ft_set_color_wild(t_point start, t_point end, int *data_color)
{
	if (start.z > 0 || end.z > 0)
		*data_color = ft_rgb_to_int(ft_clamp(255 - start.z * 50, 60, 255), \
									ft_clamp(255 - start.z * 10, 110, 255), \
									ft_clamp(abs(start.z), 0, 255));
	else if (start.z < 0 || end.z < 0)
		*data_color = ft_rgb_to_int(30, \
									ft_clamp(255 - abs(end.z) * 8, 30, 215), \
									ft_clamp(255 - abs(end.z) * 4, 30, 255));
	else
		*data_color = ft_rgb_to_int(0, 215, 255);
}

void	ft_set_color_red(t_point start, t_point end, int *data_color)
{
	if (start.z > 0 || end.z > 0)
		*data_color = ft_rgb_to_int(255, \
									ft_clamp(255 - start.z * 25, 0, 255), \
									ft_clamp(255 - start.z * 25, 0, 255));
	else if (start.z < 0 || end.z < 0)
		*data_color = ft_rgb_to_int(ft_clamp(255 - abs(start.z) * 10, 0, 255), \
									ft_clamp(255 - abs(start.z) * 10, 0, 255), \
									ft_clamp(255 - abs(start.z) * 10, 0, 255));
	else
		*data_color = ft_rgb_to_int(255, 255, 255);
}
