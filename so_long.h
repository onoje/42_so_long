/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:37 by elduran           #+#    #+#             */
/*   Updated: 2025/04/12 17:09:38 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "./includes/libft/libft.h"
# include "./includes/ft_printf/ft_printf.h"
# include "./includes/get_next_line/get_next_line.h"

typedef struct s_game
{
	char	**map;
	int		map_x;
	int		map_y;
	int		p_count;
	int		e_count;
	int		c_count;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	void	*img_collectible;
	void	*img_exit;
	void	*img_ground;
	void	*img_player;
	void	*img_wall;
	int		move_count;
}	t_game;

int		main(int argc, char **argv);
int		ft_map_char_count_control(t_game *game);
int		ft_map_valid_char_control(t_game *game);
int		ft_map_rectangular_control(t_game *game);
int		ft_map_wall_control(t_game *game);
void	ft_error_exit(t_game *game, char *msg);
int		ft_map_init(t_game *game, char *file_name);
int		ft_init_window(t_game *game);
void	ft_load_images(t_game *game);
void	ft_draw_map(t_game *game);
int		ft_exit_game(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_map_path_control(t_game *game);

#endif
