/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:46 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 18:51:54 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_control_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments!\n");
		exit(1);
	}
}

static void	ft_control_extension(char *argv)
{
	if (argv[ft_strlen(argv) - 1] != 'r' || \
		argv[ft_strlen(argv) - 2] != 'e' || \
		argv[ft_strlen(argv) - 3] != 'b' || \
		argv[ft_strlen(argv) - 4] != '.')
	{
		ft_printf("Error\nFile extension incorrect!\n");
		exit(1);
	}
	if (argv[ft_strlen(argv) - 5] == '/')
	{
		ft_printf("Error\nSecret file!\n");
		exit(1);
	}
}

static void	ft_check_all_xpm1(void)
{
	int	fd;

	fd = open("./img/player.xpm", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nxpm not found!\n");
		exit(1);
	}
	close(fd);
	fd = open("./img/ground.xpm", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nxpm not found!\n");
		exit(1);
	}
	close(fd);
	fd = open("./img/wall.xpm", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nxpm not found!\n");
		exit(1);
	}
	close(fd);
}

static void	ft_check_all_xpm2(void)
{
	int	fd;

	fd = open("./img/exit.xpm", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nxpm not found!\n");
		exit(1);
	}
	close(fd);
	fd = open("./img/collectible.xpm", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nxpm not found!\n");
		exit(1);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_all_xpm1();
	ft_check_all_xpm2();
	ft_control_argc(argc);
	ft_control_extension(argv[1]);
	ft_map_init(&game, argv[1]);
	if (ft_map_valid_char_control(&game) || \
		ft_map_char_count_control(&game) || \
		ft_map_rectangular_control(&game) || \
		ft_map_wall_control(&game) || \
		ft_map_path_control(&game))
		exit(1);
	ft_init_window(&game);
	ft_load_images(&game);
	ft_draw_map(&game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
