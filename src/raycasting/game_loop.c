/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:03:39 by rpepi             #+#    #+#             */
/*   Updated: 2024/12/30 14:50:56 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	game_loop(t_base *base)
{
	init_player_direction(base->player);
	raycasting(base);
	mlx_hook(base->mlx->win, 2, 1L << 0, handle_keypress, base);
	mlx_hook(base->mlx->win, 6, 1L << 6, handle_mouse_move, base);
	mlx_hook(base->mlx->win, 17, 1L << 17, handle_close, base);
	mlx_hook(base->mlx->win, 25, 1L << 25, handle_resize, base);
	mlx_loop(base->mlx->ptr);
}
