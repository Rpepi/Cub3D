/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:01:13 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 16:38:54 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/*
** Fonction principale du raycasting
** Gère le lancement des rayons et l'affichage de la scène 3D
*/
void	raycasting(t_base *base)
{
	t_ray_calc	rc;
	int			x;

	draw_background(base);
	x = 0;
	while (x < WIDTH)
	{
		init_ray_dir(base, &rc, x);
		calc_step_dist(&rc, base->player);
		perform_dda(&rc, base);
		calc_wall_height(&rc);
		render_wall(base, &rc, x);
		x++;
	}
	mlx_put_image_to_window(base->mlx->ptr, base->mlx->win, base->data->img, 0,
		0);
}

/*
** Calcule les paramètres nécessaires pour le rendu d'un mur
** Détermine les coordonnées de texture et les points de début/fin
*/
void	calc_wall_params(t_base *base, t_ray_calc *rc, int *line_height,
		t_draw_info *draw)
{
	double	wall_x;

	*line_height = (int)(HEIGHT / rc->perp_wall_dist);
	draw->start = -(*line_height) / 2 + HEIGHT / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = (*line_height) / 2 + HEIGHT / 2;
	if (draw->end >= HEIGHT)
		draw->end = HEIGHT - 1;
	if (rc->side == 0)
		wall_x = base->player->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		wall_x = base->player->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * 64.0);
	if (rc->side == 0 && rc->ray_dir_x > 0)
		draw->tex_x = 64 - draw->tex_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		draw->tex_x = 64 - draw->tex_x - 1;
}

/*
** Dessine une colonne de mur texturé à l'écran
** Gère l'application des textures et la perspective
*/
void	render_wall(t_base *base, t_ray_calc *rc, int x)
{
	int			line_height;
	t_draw_info	draw;
	double		step;
	double		tex_pos;
	int			tex_y;

	calc_wall_params(base, rc, &line_height, &draw);
	step = 64.0 / line_height;
	tex_pos = (draw.start - HEIGHT / 2 + line_height / 2) * step;
	while (draw.start < draw.end)
	{
		tex_y = (int)tex_pos & 63;
		tex_pos += step;
		if (x >= 0 && x < WIDTH && draw.start >= 0 && draw.start < HEIGHT)
			my_mlx_pixel_put(base->data, x, draw.start,
				get_texture_color(&base->textures[rc->tex_num], draw.tex_x,
					tex_y));
		draw.start++;
	}
}
