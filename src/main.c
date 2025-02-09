/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:03:31 by abentaye          #+#    #+#             */
/*   Updated: 2024/12/30 16:18:14 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	args_suffix_checker(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "Error\nNot enough arguments\n", 28), 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		return (write(1, "Error\n", 6), exit(1), 1);
	return (0);
}

int	init_mlx(t_base *base)
{
	base->mlx = malloc(sizeof(t_mlx));
	if (!base->mlx)
		return (free_all(base, "Malloc failed"), 1);
	base->mlx->ptr = mlx_init();
	if (!base->mlx->ptr)
		return (free_all(base, "mlx_int failed"), 1);
	base->mlx->win = mlx_new_window(base->mlx->ptr, WIDTH, HEIGHT, "cub3D");
	if (!base->mlx->win)
		return (free_all(base, "mlx_new_window failed"), 1);
	base->data->img = mlx_new_image(base->mlx->ptr, WIDTH, HEIGHT);
	if (!base->data->img)
		return (free_all(base, "mlx_new_image failed"), 1);
	base->data->addr = mlx_get_data_addr(base->data->img,
			&base->data->bits_per_pixel, &base->data->line_length,
			&base->data->endian);
	if (!base->data->addr)
		return (free_all(base, "mlx_get_data_addr failed"), 1);
	return (0);
}

// static void	display_text(t_textures *text)
// {
// 	printf("DISPLAY TEXTURES\n");
// 	printf("NO : %s\n", text->no);
// 	printf("SO : %s\n", text->so);
// 	printf("WE :%s\n", text->we);
// 	printf("EA :%s\n", text->ea);
// 	printf("F : %s\n", text->f);
// 	printf("C : %s\n", text->c);
// 	printf("set : %d\n", text->set);
// 	printf("DONE PRINTING\n");
// }

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	printf ("\nPRINTING MAP\n");
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_base	*base;
	pid_t	pid;

	args_suffix_checker(argc, argv);
	base = malloc(sizeof(t_base));
	if (!base)
		return (free_all(base, "Malloc failed"), 1);
	initialization(base, argv, argc);
	if (!base->data)
		return (free_all(base, "Initialization failed"), 1);	
	if (read_map_file(base) == NULL)
		return (free_all(base, "read_map_file failed"), 1);
	if (!base->data->map)
		return (free_all(base, "no map"), 1);
	if (init_textures_and_mlx(base) == 1)
		return (1);
	pid = fork();
	if (pid == 0)
		play_music();
	if (pid < 0)
		kill(pid, SIGKILL);
	game_loop(base);
	return (0);
}