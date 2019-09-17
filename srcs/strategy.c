/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:15:48 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 15:15:49 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_touch1(int y, int x, t_map *m)
{
	if (y + 1 < m->size_y && x + 1 < m->size_x)
		if (m->map[y + 1][x + 1] == m->e_p ||
			m->map[y + 1][x + 1] == m->e_p + 32)
			return (1);
	if (y + 1 < m->size_y && x - 1 >= 0)
		if (m->map[y + 1][x - 1] == m->e_p ||
			m->map[y + 1][x - 1] == m->e_p + 32)
			return (1);
	if (y - 1 >= 0 && x + 1 < m->size_x)
		if (m->map[y - 1][x + 1] == m->e_p ||
			m->map[y - 1][x + 1] == m->e_p + 32)
			return (1);
	if (y - 1 >= 0 && x - 1 >= 0)
		if (m->map[y - 1][x - 1] == m->e_p ||
			m->map[y - 1][x - 1] == m->e_p + 32)
			return (1);
	return (0);
}

int		ft_touch(int y, int x, t_map *m)
{
	int ret;

	ret = 0;
	ret = ret + ft_touch1(y, x, m);
	if (y + 1 < m->size_y)
		if (m->map[y + 1][x] == m->e_p || m->map[y + 1][x] == m->e_p + 32)
			ret++;
	if (x - 1 >= 0)
		if (m->map[y][x - 1] == m->e_p || m->map[y][x - 1] == m->e_p + 32)
			ret++;
	if (y - 1 >= 0)
		if (m->map[y - 1][x] == m->e_p || m->map[y - 1][x] == m->e_p + 32)
			ret++;
	if (x - 1 >= 0)
		if (m->map[y][x - 1] == m->e_p || m->map[y][x - 1] == m->e_p + 32)
			ret++;
	return (ret);
}

void	ft_strategy_1(t_map *map, t_piece *p)
{
	int		i;
	int		j;
	int		dist;

	i = -1;
	while (++i < p->pp_size)
	{
		j = -1;
		dist = 99999;
		while (++j < map->ep_size)
		{
			if (ft_dist(p->possible_pos[i][0], map->enemy_pos[j][0],
				p->possible_pos[i][1], map->enemy_pos[j][1]) < dist)
				dist = ft_dist(p->possible_pos[i][0], map->enemy_pos[j][0],
				p->possible_pos[i][1], map->enemy_pos[j][1]);
		}
		p->possible_pos[i][2] = dist;
	}
}

void	ft_strategy_2(t_map *map, t_piece *p)
{
	int		i;
	int		j;
	int		k;
	int		nbr;

	k = -1;
	while (++k < p->pp_size)
	{
		nbr = 0;
		j = -1;
		while (++j < p->psize_y)
		{
			i = -1;
			while (++i < p->psize_x)
				if (p->piece[j][i] == '*')
					nbr += ft_touch(p->possible_pos[k][0] + j,
						p->possible_pos[k][1] + i, map);
		}
		p->possible_pos[k][2] = nbr;
	}
}

void	ft_strategy_3(t_map *map, t_piece *p)
{
	int		i;

	i = 0;
	p->fin_pos[0] = p->possible_pos[i][0];
	p->fin_pos[1] = p->possible_pos[i][1];
	p->fin_pos[2] = p->possible_pos[i][2];
	if (ft_is_touching(map))
		while (++i < p->pp_size)
		{
			if (p->possible_pos[i][2] > p->fin_pos[2])
			{
				p->fin_pos[0] = p->possible_pos[i][0];
				p->fin_pos[1] = p->possible_pos[i][1];
				p->fin_pos[2] = p->possible_pos[i][2];
			}
		}
	else
		while (++i < p->pp_size)
			if (p->possible_pos[i][2] <= p->fin_pos[2])
			{
				p->fin_pos[0] = p->possible_pos[i][0];
				p->fin_pos[1] = p->possible_pos[i][1];
				p->fin_pos[2] = p->possible_pos[i][2];
			}
}
