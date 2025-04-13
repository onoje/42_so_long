/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:10:18 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 18:21:03 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_char_count(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_count++;
				game->p_x = x;
				game->p_y = y;
			}
			if (game->map[y][x] == 'C')
				game->c_count++;
			if (game->map[y][x] == 'E')
				game->e_count++;
			x++;
		}
		y++;
	}
}

int	ft_map_char_count_control(t_game *game)
{
	game->p_count = 0;
	game->e_count = 0;
	game->c_count = 0;
	ft_map_char_count(game);
	if (game -> e_count != 1)
		ft_error_exit(game, "Exit (E) must be exactly 1!");
	if (game -> p_count != 1)
		ft_error_exit(game, "Player (P) must be exactly 1!");
	if (game -> c_count == 0)
		ft_error_exit(game, "At least one collectible (C) required!");
	return (0);
}

int	ft_map_valid_char_control(t_game *game)
{
	int		y;
	int		x;
	char	*valid_chars;

	valid_chars = "01CEP\n";
	y = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			if (!(ft_strchr(valid_chars, game -> map[y][x])))
				ft_error_exit(game, "Invalid character detected!");
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map_rectangular_control(t_game *game)
{
	int	y;
	int	len;

	y = 0;
	while (game -> map[y])
	{
		len = ft_strlen(game -> map[y]);
		if (game -> map[y][len - 1] == '\n')
			len--;
		if (len != game -> map_x)
			ft_error_exit(game, "Map not rectangular or unexpected new line!");
		y++;
	}
	return (0);
}

int	ft_map_wall_control(t_game *game)
{
	int	x;

	x = 0;
	while (x < (game -> map_x))
	{
		if (game -> map[0][x] != '1' || game -> map[game->map_y - 1][x] != '1')
			ft_error_exit(game, "Top or bottom wall is missing!");
		x++;
	}
	x = 0;
	while (x < (game -> map_y))
	{
		if (game->map[x][0] != '1' || game->map[x][game->map_x - 1] != '1')
			ft_error_exit(game, "Side wall is missing!");
		x++;
	}
	return (0);
}
