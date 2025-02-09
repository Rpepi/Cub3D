/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:14:20 by abentaye          #+#    #+#             */
/*   Updated: 2024/11/11 12:39:34 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_keep(int fd, char *remn_str)
{
	char	*buff;
	int		count_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	count_bytes = 1;
	while (!ft_strchr(remn_str, '\n') && count_bytes != 0)
	{
		count_bytes = read(fd, buff, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(remn_str);
			free(buff);
			return (NULL);
		}
		buff[count_bytes] = '\0';
		remn_str = ft_strjoin(remn_str, buff);
	}
	free(buff);
	return (remn_str);
}

char	*get_next_line(int fd)
{
	static char	*remn_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remn_str = read_and_keep(fd, remn_str);
	if (!remn_str)
		return (NULL);
	line = ft_get_line(remn_str);
	remn_str = new_remn_str(remn_str);
	return (line);
}

/*int    main(void)
{
	char    *line;
	int        i;
	int        fd1;
	int        fd2;
	int        fd3;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
