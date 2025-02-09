/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:18:28 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/30 16:18:41 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_text(t_textures *text)
{
	if (text->no)
		free(text->no);
	if (text->so)
		free(text->so);
	if (text->we)
		free(text->we);
	if (text->ea)
		free(text->ea);
	if (text->f)
		free(text->f);
	if (text->c)
		free(text->c);
}

void	free_all(t_base *base, char *str)
{
	if (base->map)
	{
		if (base->map->fparams)
			free(base->map->fparams);
		free(base->map);
	}
	if (base->player)
		free(base->player);
	if (base->data)
		free(base->data);
	if (base->mlx)
		free(base->mlx);
	if (base->text)
	{
		free_text(base->text);
		free(base->text);
	}
	kill(0, SIGKILL);
	write(1, "Error\n", 6);
	printf("%s\n", str);
	exit(1);
}

void	free_textures(t_base *base)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (base->textures[i].img)
			mlx_destroy_image(base->mlx->ptr, base->textures[i].img);
		i++;
	}
}
