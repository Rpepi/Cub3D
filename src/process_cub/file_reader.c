/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:39:54 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/30 16:11:17 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	size_map(char **split, int i)
{
	int	j;

	j = 0;
	while (split[j])
		j++;
	return (j - i + 1);
}

char	**new_get_map(t_base *base, char **split, int i)
{
	char	**map;
	int		j;
	int		line_len;
	int		split_len;

	j = 0;
	map = malloc(sizeof(char *) * size_map(split, i));
	if (!map)
		return (free_all(base, "malloc failed"), NULL);
	line_len = longest_line(split);
	while (split[i])
	{
		map[j] = malloc(sizeof(char *) * line_len);
		if (!map[j])
			return (free_all(base, "malloc failed"), NULL);
		split_len = ft_strlen(split[i]);
		ft_memcpy(map[j], split[i], split_len);
		ft_memset(map[j] + split_len, 0, line_len - split_len);
		map[j][line_len] = 0;
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

static int	process_buffer(t_base *base, char *buffer)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(buffer, '\n');
	while (split[i])
	{
		fill_textures(base->text, split[i]);
		if (base->text->set == 1)
			break ;
		i++;
	}
	if (text_checker(base) == 1)
	{
		if (split)
			ft_free_split(split);
		return (free_all(base, "text are not available"), -1);
	}
	base->data->map = new_get_map(base, split, i + 1);
	if (split)
		ft_free_split(split);
	return (i);
}

static int	read_valid(int fd, t_base *base)
{
	char	*buffer;
	int		b_read;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (free_all(base, "malloc failed"), 1);
	b_read = read(fd, buffer, BUFFER_SIZE - 1);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		if (process_buffer(base, buffer) == -1)
			return (free_all(base, "malloc failed"), 1);
		if (buffer[0] == '\0')
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	if (b_read < 0)
		return (free_all(base, "malloc failed"), 1);
	if (buffer)
		free(buffer);
	close(fd);
	return (0);
}

t_base	*read_map_file(t_base *base)
{
	int		fd;

	fd = open(base->map_name, O_RDONLY);
	if (fd < 0 || !base->map_name)
	{
		perror("Can't open file");
		return (NULL);
	}
	else
	{
		if (read_valid(fd, base))
			return (NULL);
		if (base->data->map)
		{
			if (valid_map(base) == 1)
			{
				return (free_all(base, "map is not valid"), NULL);
			} 
		}
	}
	close(fd);
	return (base);
}
