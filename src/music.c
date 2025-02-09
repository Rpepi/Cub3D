/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:49 by pepi              #+#    #+#             */
/*   Updated: 2024/12/17 14:36:36 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	play_music(void)
{
	char	**music_args;

	music_args = malloc(sizeof(char *) * 3);
	if (!music_args)
		return ;
	music_args[0] = "afplay";
	music_args[1] = "./music/music2.mp3";
	music_args[2] = NULL;
	execvp("afplay", music_args);
	free(music_args);
	perror("Erreur lors du lancement de la musique");
	exit(1);
}
