/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_forward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:01:59 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 14:45:32 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move_forward(t_base *base)
{
	double	new_x;
	double	new_y;

	new_x = base->player->pos_x + base->player->dir_x
		* base->player->move_speed;
	new_y = base->player->pos_y + base->player->dir_y
		* base->player->move_speed;
	if (check_collision_x(base, new_x))
		base->player->pos_x = new_x;
	if (check_collision_y(base, new_y))
		base->player->pos_y = new_y;
}

void	move_backward(t_base *base)
{
	double	new_x;
	double	new_y;

	new_x = base->player->pos_x - base->player->dir_x
		* base->player->move_speed;
	new_y = base->player->pos_y - base->player->dir_y
		* base->player->move_speed;
	if (check_collision_x(base, new_x))
		base->player->pos_x = new_x;
	if (check_collision_y(base, new_y))
		base->player->pos_y = new_y;
}
