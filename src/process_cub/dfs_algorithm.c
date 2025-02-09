/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:50:23 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/17 22:50:44 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	dfs(char **map, int x, int y, t_params *params)
{
	bool	up;
	bool	down;
	bool	right;
	bool	left;

	if (x < 0 || x >= params->rows || y < 0 || y >= params->cols)
		return (false);
	if (!map[x][y])
		return (false);
	if (map[x][y] == '1' || map[x][y] == 'o')
		return (true);
	map[x][y] = params->new_color;
	up = dfs(map, x - 1, y, params);
	down = dfs(map, x + 1, y, params);
	left = dfs(map, x, y - 1, params);
	right = dfs(map, x, y + 1, params);
	return (up && down && left && right);
}

int	floodfill(t_base *base)
{
	int		x;
	int		y;
	char	oc;

	base->map->fparams->rows = 0;
	base->map->fparams->cols = ft_strlen(base->data->map[0]);
	base->map->fparams->new_color = 'o';
	x = base->player->pos_x;
	y = base->player->pos_y;
	oc = base->data->map[x][y];
	base->data->map[x][y] = '0';
	if (oc == '1' || oc == 'o')
		return (1);
	while (base->data->map[base->map->fparams->rows])
		base->map->fparams->rows++;
	if (dfs(base->data->map, x, y, base->map->fparams) == true)
		return (0);
	else
		return (1);
}
