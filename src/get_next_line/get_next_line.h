/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:41:51 by abentaye          #+#    #+#             */
/*   Updated: 2024/11/11 10:59:25 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../includes/cub3d.h"
# include "../../libft/libft.h"

char	*get_next_line(int fd);
char	*read_and_keep(int fd, char *remn_str);
char	*ft_get_line(char *remn_str);
char	*new_remn_str(char *remn_str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
