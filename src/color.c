/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:24:57 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 16:26:24 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	validate_rgb_value(char *color, int *i)
{
	int	value;

	value = ft_atoi(color + *i);
	if (value < 0 || value > 255)
		return (-1);
	while (color[*i] && ft_isdigit(color[*i]))
		(*i)++;
	if (color[*i] && color[*i] != ',')
		return (-1);
	if (color[*i] == ',')
		(*i)++;
	return (value);
}

unsigned int	create_rgb(char *color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (color[i] && ft_isspace(color[i]))
		i++;
	r = validate_rgb_value(color, &i);
	if (r == -1)
		return (-1);
	g = validate_rgb_value(color, &i);
	if (g == -1)
		return (-1);
	b = validate_rgb_value(color, &i);
	if (b == -1)
		return (-1);
	while (color[i] && ft_isspace(color[i]))
		i++;
	if (color[i] != '\0')
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
