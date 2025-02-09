/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:14:48 by pepi              #+#    #+#             */
/*   Updated: 2024/12/23 13:30:50 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	load_single_texture(t_base *base, t_texture_data *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(base->mlx->ptr, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
		return (1);
	return (0);
}

int	load_textures(t_base *base)
{
	if (load_single_texture(base, &base->textures[1], base->text->no)
		|| load_single_texture(base, &base->textures[0], base->text->so)
		|| load_single_texture(base, &base->textures[3], base->text->we)
		|| load_single_texture(base, &base->textures[2], base->text->ea))
		return (1);
	return (0);
}

int	verify_texture_dimensions(t_base *base)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (base->textures[i].width != 64 || base->textures[i].height != 64)
		{
			printf("Erreur: La texture %d n'a pas les dimensions 64x64\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	draw_textured_line(t_data *data, t_draw_line_params *params)
{
	t_draw_params	draw;

	if (!params->tex || !params->tex->addr || params->tex_x < 0
		|| params->tex_x >= params->tex->width)
		return ;
	if (params->end <= params->start)
		return ;
	draw.x = params->x;
	draw.start = params->start;
	draw.end = params->end;
	draw.tex = params->tex;
	draw.tex_x = params->tex_x;
	draw.step = 64.0 / (params->end - params->start);
	draw.tex_pos = 0;
	draw_texture_line_part(data, &draw);
}

unsigned int	get_texture_color(t_texture_data *tex, int x, int y)
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
