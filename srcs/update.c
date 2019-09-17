/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:25:58 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 15:26:20 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_count(char **map, char c, int size_y, int size_x)
{
	int		count;
	char	cap;
	int		y;
	int		x;

	count = 0;
	cap = c + 32;
	y = -1;
	while (++y < size_y)
	{
		x = -1;
		while (++x < size_x)
			if (map[y][x] == c || map[y][x] == cap)
				count++;
	}
	return (count);
}

void	ft_get_enemypos(t_map *m)
{
	char	**map;
	int		x;
	int		y;
	int		size;
	int		count;

	map = m->map;
	y = -1;
	size = 0;
	count = ft_count(map, m->e_p, m->size_y, m->size_x);
	m->ep_size = count;
	m->enemy_pos = (int**)malloc(sizeof(int*) * count);
	while (++y < m->size_y)
	{
		x = -1;
		while (++x < m->size_x)
			if (map[y][x] == m->e_p || map[y][x] == m->e_p + 32)
			{
				m->enemy_pos[size] = (int*)malloc(sizeof(int) * 2);
				m->enemy_pos[size][0] = y;
				m->enemy_pos[size][1] = x;
				size++;
			}
	}
}

void	ft_get_mypos(t_map *m)
{
	char	**map;
	int		x;
	int		y;
	int		size;
	int		count;

	map = m->map;
	y = -1;
	size = 0;
	count = ft_count(map, m->m_p, m->size_y, m->size_x);
	m->mp_size = count;
	m->my_pos = (int**)malloc(sizeof(int*) * count);
	while (++y < m->size_y)
	{
		x = -1;
		while (++x < m->size_x)
			if (map[y][x] == m->m_p || map[y][x] == m->m_p + 32)
			{
				m->my_pos[size] = (int*)malloc(sizeof(int) * 2);
				m->my_pos[size][0] = y;
				m->my_pos[size][1] = x;
				size++;
			}
	}
}
