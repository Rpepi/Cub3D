/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:01:00 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 16:38:40 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/*
** Met à jour la position du rayon lors du DDA (Digital Differential Analysis)
** Détermine si le rayon touche un mur vertical ou horizontal
*/
static void	update_ray_position(t_ray_calc *rc)
{
	if (rc->side_dist_x < rc->side_dist_y)
	{
		rc->side_dist_x += rc->delta_dist_x;
		rc->map_x += rc->step_x;
		rc->side = 0;
	}
	else
	{
		rc->side_dist_y += rc->delta_dist_y;
		rc->map_y += rc->step_y;
		rc->side = 1;
	}
}

/*
** Implémente l'algorithme DDA pour la détection des collisions
** Calcule la distance jusqu'au prochain mur et détermine la texture à utiliser
*/
void	perform_dda(t_ray_calc *rc, t_base *base)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		update_ray_position(rc);
		if (base->data->map[rc->map_x]
			&& base->data->map[rc->map_x][rc->map_y] == '1')
			hit = 1;
		if (rc->side == 0)
		{
			if (rc->ray_dir_x > 0)
				rc->tex_num = 0;
			else
				rc->tex_num = 1;
		}
		else
		{
			if (rc->ray_dir_y > 0)
				rc->tex_num = 2;
			else
				rc->tex_num = 3;
		}
	}
}

/*
** Calcule la hauteur du mur à afficher à l'écran
** Détermine les points de début et de fin du mur sur l'écran
*/
void	calc_wall_height(t_ray_calc *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	else
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
	if (rc->perp_wall_dist <= 0)
		rc->perp_wall_dist = 0.1;
	rc->line_height = (int)(HEIGHT / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + HEIGHT / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + HEIGHT / 2;
	if (rc->draw_end >= HEIGHT)
		rc->draw_end = HEIGHT - 1;
}
