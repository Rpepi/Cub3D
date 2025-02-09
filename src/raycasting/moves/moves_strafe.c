/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_strafe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:02:34 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/17 14:10:47 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_collision_x(t_base *base, double new_x)
{
	char	next_pos;

	next_pos = base->data->map[(int)new_x][(int)base->player->pos_y];
	return (next_pos != '1');
}

int	check_collision_y(t_base *base, double new_y)
{
	char	next_pos;

	next_pos = base->data->map[(int)base->player->pos_x][(int)new_y];
	return (next_pos != '1');
}

void	move_left(t_base *base)
{
	double	new_x;
	double	new_y;

	new_x = base->player->pos_x - base->player->plane_x
		* base->player->move_speed;
	new_y = base->player->pos_y - base->player->plane_y
		* base->player->move_speed;
	if (check_collision_x(base, new_x))
		base->player->pos_x = new_x;
	if (check_collision_y(base, new_y))
		base->player->pos_y = new_y;
}

void	move_right(t_base *base)
{
	double	new_x;
	double	new_y;

	new_x = base->player->pos_x + base->player->plane_x
		* base->player->move_speed;
	new_y = base->player->pos_y + base->player->plane_y
		* base->player->move_speed;
	if (check_collision_x(base, new_x))
		base->player->pos_x = new_x;
	if (check_collision_y(base, new_y))
		base->player->pos_y = new_y;
}
