/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:05:49 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/23 13:32:31 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	init_player_dir_ns(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->dir == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static void	init_player_dir_ew(t_player *player)
{
	if (player->dir == 'E')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

void	init_player_direction(t_player *player)
{
	init_player_dir_ns(player);
	init_player_dir_ew(player);
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}
