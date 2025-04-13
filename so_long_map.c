/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:51 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 18:21:31 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(t_game *game, char *msg)
{
	int	i;

	ft_printf("Error\n%s\n", msg);
	if (game && game -> map)
	{
		i = 0;
		while (game -> map[i])
			free(game -> map[i++]);
		free(game -> map);
	}
	exit(1);
}

static int	ft_map_line_count(char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static char	**ft_map_read_lines(int fd, int line_count)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static char	**ft_map_read(char *file_name, int line_count)
{
	int		fd;
	char	**map;
	char	*extra_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_map_read_lines(fd, line_count);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	extra_line = get_next_line(fd);
	if (extra_line)
		free(extra_line);
	close(fd);
	return (map);
}

int	ft_map_init(t_game *game, char *file_name)
{
	game -> move_count = 0;
	game -> map_y = ft_map_line_count(file_name);
	if (game -> map_y <= 0)
	{
		ft_printf("Error\nMap couldn't be read or is empty!\n");
		exit(1);
	}
	game -> map = ft_map_read(file_name, game -> map_y);
	if (!(game -> map))
		ft_error_exit(game, "Map could not be initialized!");
	game -> map_x = ft_strlen(game -> map[0]);
	if (game -> map[0][game -> map_x - 1] == '\n')
		game -> map_x--;
	return (0);
}
