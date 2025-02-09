/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:50:17 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/30 16:11:21 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	text_checker(t_base *base)
{
	if ((open(base->text->no, O_RDONLY)) == -1)
		return (free_all(base, "Error textures"), 1);
	if ((open(base->text->ea, O_RDONLY)) == -1)
		return (free_all(base, "Error textures"), 1);
	if ((open(base->text->so, O_RDONLY)) == -1)
		return (free_all(base, "Error textures"), 1);
	if ((open(base->text->we, O_RDONLY)) == -1)
		return (free_all(base, "Error textures"), 1);
	return (0);
}

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

char	*param_format(char *param)
{
	int		i;
	int		j;
	char	*formed;

	formed = (char *)malloc(strlen(param) - 1);
	i = 2;
	j = 0;
	while (param[i])
	{
		if (param[i] == '\n')
			break ;
		if (ft_isspace(param[i]) == 0)
		{
			formed[j] = param[i];
			j++;
		}
		i++;
	}
	formed[j] = '\0';
	return (formed);
}

t_textures	*fill_textures(t_textures *text, char *param)
{
	if (!param && text->set != 1)
		return (NULL);
	else if (ft_strncmp(param, "NO ", 3) == 0 && text->no != param)
		text->no = param_format(param);
	else if (ft_strncmp(param, "EA ", 3) == 0 && text->ea != param)
		text->ea = param_format(param);
	else if (ft_strncmp(param, "SO ", 3) == 0 && text->so != param)
		text->so = param_format(param);
	else if (ft_strncmp(param, "WE ", 3) == 0 && text->we != param)
		text->we = param_format(param);
	else if (ft_strncmp(param, "F ", 2) == 0 && text->f != param)
		text->f = param_format(param);
	else if (ft_strncmp(param, "C ", 2) == 0 && text->c != param)
		text->c = param_format(param);
	else
		return (text->set = -1, NULL);
	if (text->no && text->ea && text->so && text->we && text->f && text->c)
	{
		text->set = 1;
		return (text);
	}
	return (text);
}
