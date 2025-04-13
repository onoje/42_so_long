/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path_control.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:10:10 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 17:10:11 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_map_copy(char **map, int line_count)
{
	char	**copy_map;
	int		i;

	copy_map = malloc(sizeof(char *) * (line_count + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		copy_map[i] = ft_strdup(map[i]);
		if (!copy_map[i])
		{
			i--;
			while (i >= 0)
				free(copy_map[i--]);
			free(copy_map);
			return (NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

static void	ft_map_fill(char **map, int x, int y)
{
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P')
		return ;
	map[y][x] = 'F';
	ft_map_fill(map, x + 1, y);
	ft_map_fill(map, x - 1, y);
	ft_map_fill(map, x, y + 1);
	ft_map_fill(map, x, y - 1);
}

static int	ft_map_remain_char_control(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map_path_control(t_game *game)
{
	char	**copy_map;
	int		i;

	copy_map = ft_map_copy(game->map, game->map_y);
	if (!copy_map)
		ft_error_exit(game, "Map copy failed!");
	ft_map_fill(copy_map, game->p_x, game->p_y);
	if (ft_map_remain_char_control(copy_map))
	{
		i = 0;
		while (copy_map[i])
			free(copy_map[i++]);
		free(copy_map);
		ft_error_exit(game, "Not all collectibles or exit are reachable!");
	}
	i = 0;
	while (copy_map[i])
		free(copy_map[i++]);
	free(copy_map);
	return (0);
}
