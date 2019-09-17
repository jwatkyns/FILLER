/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:59:06 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 16:04:20 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_map
{
	char	**map;
	int		player;
	int		size_x;
	int		size_y;
	char	e_p;
	char	m_p;
	int		**enemy_pos;
	int		ep_size;
	int		**my_pos;
	int		mp_size;
	int		strategy;
	int		touch;
	int		ret;
}				t_map;

typedef	struct	s_piece
{
	char	**piece;
	int		psize_x;
	int		psize_y;
	int		**possible_pos;
	int		pp_size;
	int		fin_pos[3];
}				t_piece;

void			ft_init_struct(t_map *map, t_piece *p);
void			ft_initialise_info(t_map *map);
void			ft_get_mypos(t_map *mapping);
void			ft_get_enemypos(t_map *mapping);
void			ft_mapsize(t_map *map, char *line);
void			ft_get_map(t_map *map);
void			ft_get_piece(t_piece *p);
void			ft_get_positions(t_map *map, t_piece *p);
int				ft_piece_map(t_map *map, t_piece *p, int x, int y);
void			ft_print_final(t_piece *p);
void			ft_print_end(void);
void			ft_get_enemy_info(t_map *map, t_piece *p);
void			ft_strategy_1(t_map *map, t_piece *p);
void			ft_strategy_2(t_map *map, t_piece *p);
void			ft_strategy_3(t_map *map, t_piece *p);
int				ft_is_touching(t_map *map);
int				ft_dist(int x1, int x2, int y1, int y2);

#endif
