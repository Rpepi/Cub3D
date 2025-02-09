/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:00:51 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 17:05:16 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/*
** Initialise les paramètres du rayon pour le raycasting
** Calcule la direction du rayon et sa position initiale
*/
void	init_ray_dir(t_base *base, t_ray_calc *rc, int x)
{
	rc->camera_x = 2 * x / (double)WIDTH - 1;
	rc->ray_dir_x = base->player->dir_x + base->player->plane_x * rc->camera_x;
	rc->ray_dir_y = base->player->dir_y + base->player->plane_y * rc->camera_x;
	rc->map_x = (int)base->player->pos_x;
	rc->map_y = (int)base->player->pos_y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	rc->hit = 0;
}

/*
** Calcule les distances et les pas pour l'algorithme DDA
** Détermine la direction et la longueur des pas pour le rayon
*/
void	calc_step_dist(t_ray_calc *rc, t_player *player)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (player->pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - player->pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (player->pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - player->pos_y) * rc->delta_dist_y;
	}
}
