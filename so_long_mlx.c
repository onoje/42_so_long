/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:58 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 17:09:59 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_window(t_game *game)
{
	game -> mlx = mlx_init();
	if (!(game -> mlx))
		ft_error_exit(game, "Failed to initialize MLX!");
	game -> win = mlx_new_window(game -> mlx,
			game -> map_x * 64,
			game -> map_y * 64,
			"so_long");
	if (!(game -> win))
		ft_error_exit(game, "Failed to create window!");
	return (0);
}

void	ft_load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./img/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &w, &h);
	game->img_ground = mlx_xpm_file_to_image(game->mlx,
			"./img/ground.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &w, &h);
}

static void	ft_draw_xpm(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img_wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img_ground, x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img_player, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img_collectible, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(game -> mlx, game -> win,
			game -> img_exit, x * 64, y * 64);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			ft_draw_xpm(game, game -> map[y][x], x, y);
			x++;
		}
		y++;
	}
}
