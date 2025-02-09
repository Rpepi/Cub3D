/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:39:50 by abentaye          #+#    #+#             */
/*   Updated: 2024/11/11 15:26:16 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *remn_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!remn_str)
// 	{
// 		remn_str = (char *)malloc(1 * sizeof(char));
// 		remn_str[0] = '\0';
// 	}
// 	if (!remn_str || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(remn_str) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (remn_str)
// 		while (remn_str[++i] != '\0')
// 			str[i] = remn_str[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(remn_str) + ft_strlen(buff)] = '\0';
// 	free(remn_str);
// 	return (str);
// }

char	*ft_get_line(char *remn_str)
{
	int			i;
	char		*str;

	i = 0;
	if (!remn_str[i])
		return (NULL);
	while (remn_str[i] && remn_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remn_str[i] && remn_str[i] != '\n')
	{
		str[i] = remn_str[i];
		i++;
	}
	if (remn_str[i] == '\n')
	{
		str[i] = remn_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_remn_str(char *remn_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remn_str[i] && remn_str[i] != '\n')
		i++;
	if (!remn_str[i])
	{
		free(remn_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remn_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remn_str[i])
		str[j++] = remn_str[i++];
	str[j] = '\0';
	free(remn_str);
	return (str);
}
