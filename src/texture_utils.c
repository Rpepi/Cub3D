/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:15:21 by pepi              #+#    #+#             */
/*   Updated: 2024/12/17 16:28:00 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	get_pixel_color(t_texture_data *tex, int x, int y)
{
	char	*pixel;
	int		offset;

	if (!tex || !tex->addr || x < 0 || y < 0 || x >= tex->width
		|| y >= tex->height)
		return (0xFF000000);
	offset = (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	if (offset < 0)
		return (0xFF000000);
	pixel = tex->addr + offset;
	return (*(unsigned int *)pixel);
}

void	draw_texture_line_part(t_data *data, t_draw_params *params)
{
	int				y;
	unsigned int	color;
	int				tex_y;

	y = params->start;
	while (y < params->end && y < HEIGHT)
	{
		if (y >= 0)
		{
			tex_y = (int)params->tex_pos & 63;
			color = get_pixel_color(params->tex, params->tex_x, tex_y);
			my_mlx_pixel_put(data, params->x, y, color);
		}
		params->tex_pos += params->step;
		y++;
	}
}

static void	draw_background_line(t_data *data, int y,
		unsigned int ceiling_color, unsigned int floor_color)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		if (y < HEIGHT / 2)
			my_mlx_pixel_put(data, x, y, ceiling_color);
		else
			my_mlx_pixel_put(data, x, y, floor_color);
		x++;
	}
}

void	draw_background(t_base *base)
{
	int				y;
	unsigned int	ceiling_color;
	unsigned int	floor_color;

	ceiling_color = create_rgb(base->text->c);
	floor_color = create_rgb(base->text->f);
	y = 0;
	while (y < HEIGHT)
	{
		draw_background_line(base->data, y, ceiling_color, floor_color);
		y++;
	}
}
