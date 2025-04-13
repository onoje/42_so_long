/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:10:06 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 17:10:07 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game -> map && game -> map[i])
		free(game -> map[i++]);
	free(game -> map);
	if (game -> img_wall)
		mlx_destroy_image(game -> mlx, game -> img_wall);
	if (game -> img_ground)
		mlx_destroy_image(game -> mlx, game -> img_ground);
	if (game -> img_player)
		mlx_destroy_image(game -> mlx, game -> img_player);
	if (game -> img_collectible)
		mlx_destroy_image(game -> mlx, game -> img_collectible);
	if (game -> img_exit)
		mlx_destroy_image(game -> mlx, game -> img_exit);
	if (game -> win)
		mlx_destroy_window(game -> mlx, game -> win);
	if (game -> mlx)
	{
		mlx_destroy_display(game -> mlx);
		free(game -> mlx);
	}
	exit(0);
	return (0);
}

static void	ft_move_player(t_game *game, int x, int y)
{
	if (game -> map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E')
	{
		if (game->c_count == 0)
			ft_exit_game(game);
		else
			return ;
	}
	if (game -> map[y][x] == 'C')
		game -> c_count--;
	game -> map[game -> p_y][game -> p_x] = '0';
	game -> map[y][x] = 'P';
	game -> p_x = x;
	game -> p_y = y;
	game -> move_count++;
	ft_printf("Move Count: %d\n", game -> move_count);
	ft_draw_map(game);
}

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game -> p_x;
	y = game -> p_y;
	if (keycode == 65307)
		ft_exit_game(game);
	else if (keycode == 'w')
		y--;
	else if (keycode == 's')
		y++;
	else if (keycode == 'a')
		x--;
	else if (keycode == 'd')
		x++;
	else
		return (0);
	ft_move_player(game, x, y);
	return (0);
}
