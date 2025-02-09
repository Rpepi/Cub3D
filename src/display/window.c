/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:18 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/30 16:11:04 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	init_base_data(t_base *base)
{
	base->data = malloc(sizeof(t_data));
	if (!base->data)
		return (1);
	base->data->addr = NULL;
	base->data->bits_per_pixel = 0;
	base->data->endian = 0;
	base->data->img = NULL;
	base->data->line_length = 0;
	base->data->map = NULL;
	base->map->fparams = malloc(sizeof(t_params));
	if (!base->map->fparams)
		return (1);
	base->map->fparams->cols = 0;
	base->map->fparams->new_color = 0;
	base->map->fparams->old_color = 0;
	return (0);
}

static int	init_text(t_base *base)
{
	base->text = malloc(sizeof(t_textures));
	if (!base->text)
		return (1);
	base->text->c = NULL;
	base->text->ea = NULL;
	base->text->f = NULL;
	base->text->no = NULL;
	base->text->so = NULL;
	base->text->we = NULL;
	base->text->set = 0;
	return (0);
}

static int	init_player(t_base *base)
{
	base->player = malloc(sizeof(t_player));
	if (!base->player)
		return (1);
	base->player->dir = 0;
	base->player->pos_x = 0;
	base->player->pos_y = 0;
	base->player->angle = 0;
	base->player->fov = 0;
	return (0);
}

static int	init_map(t_base *base)
{
	base->map = malloc(sizeof(t_map));
	if (!base->map)
		return (1);
	base->map->character = 0;
	base->map->closed = 0;
	base->map->invalid = 0;
	return (0);
}

void	initialization(t_base *base, char **argv, int argc)
{
	if (argc != 2)
		return (exit(1));
	base->map_name = argv[1];
	base->mlx = NULL;
	if (init_player(base) == 1)
		free_all(base, "Initialization failed");
	if (init_map(base) == 1)
		free_all(base, "Initialization failed");
	if (init_base_data(base) == 1)
		free_all(base, "Initialization failed");
	if (!base->data)
		free_all(base, "Initialization failed");
	if (init_text(base) == 1)
		free_all(base, "Initialization failed");
}
