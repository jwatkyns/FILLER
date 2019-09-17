/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:41:57 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 15:42:13 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_enemy_info(t_map *map, t_piece *p)
{
	int i;

	i = -1;
	if (!(ft_is_touching(map)))
		ft_strategy_1(map, p);
	else
		ft_strategy_2(map, p);
	ft_strategy_3(map, p);
}

int		ft_is_touching2(t_map *m)
{
	int		i;

	i = -1;
	while (++i < m->mp_size)
	{
		if (m->my_pos[i][0] + 1 < m->size_y && m->my_pos[i][1] + 1 < m->size_x)
			if (m->map[m->my_pos[i][0] + 1][m->my_pos[i][1] + 1] == m->e_p ||
			m->map[m->my_pos[i][0] + 1][m->my_pos[i][1] + 1] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][0] + 1 < m->size_y && m->my_pos[i][1] - 1 >= 0)
			if (m->map[m->my_pos[i][0] + 1][m->my_pos[i][1] - 1] == m->e_p ||
			m->map[m->my_pos[i][0] + 1][m->my_pos[i][1] - 1] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][0] - 1 >= 0 && m->my_pos[i][1] + 1 < m->size_x)
			if (m->map[m->my_pos[i][0] - 1][m->my_pos[i][1] + 1] == m->e_p ||
			m->map[m->my_pos[i][0] - 1][m->my_pos[i][1] + 1] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][0] - 1 >= 0 && m->my_pos[i][1] - 1 >= 0)
			if (m->map[m->my_pos[i][0] - 1][m->my_pos[i][1] - 1] == m->e_p ||
			m->map[m->my_pos[i][0] - 1][m->my_pos[i][1] - 1] == m->e_p + 32)
				return (1);
	}
	return (0);
}

int		ft_is_touching(t_map *m)
{
	int		i;

	i = -1;
	while (++i < m->mp_size)
	{
		if (m->my_pos[i][0] + 1 < m->size_y)
			if (m->map[m->my_pos[i][0] + 1][m->my_pos[i][1]] == m->e_p ||
				m->map[m->my_pos[i][0] + 1][m->my_pos[i][1]] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][1] + 1 < m->size_x)
			if (m->map[m->my_pos[i][0]][m->my_pos[i][1] + 1] == m->e_p ||
				m->map[m->my_pos[i][0]][m->my_pos[i][1] + 1] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][0] - 1 >= 0)
			if (m->map[m->my_pos[i][0] - 1][m->my_pos[i][1]] == m->e_p ||
				m->map[m->my_pos[i][0] - 1][m->my_pos[i][1]] == m->e_p + 32)
				return (1);
		if (m->my_pos[i][1] - 1 >= 0)
			if (m->map[m->my_pos[i][0]][m->my_pos[i][1] - 1] == m->e_p ||
				m->map[m->my_pos[i][0]][m->my_pos[i][1] - 1] == m->e_p + 32)
				return (1);
	}
	return (ft_is_touching2(m));
}

int		ft_dist(int x1, int x2, int y1, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
