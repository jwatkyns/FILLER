/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:02:14 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 15:02:17 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_no_pos(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;

	y = -1;
	i = 0;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x < map->size_x)
		{
			flag = ft_piece_map(map, p, x, y);
			if (flag == 1)
				i++;
		}
	}
	return (i);
}

int		ft_position(t_piece *p, int y, int x, int i)
{
	p->possible_pos[i] = (int*)malloc(sizeof(int) * 3);
	p->possible_pos[i][0] = y;
	p->possible_pos[i][1] = x;
	p->possible_pos[i++][2] = 0;
	return (i);
}

void	ft_get_positions(t_map *map, t_piece *p)
{
	int	x;
	int	y;
	int	i;
	int	flag;
	int	count;

	y = -1;
	i = 0;
	count = ft_get_no_pos(map, p);
	p->pp_size = count;
	if (count == 0)
		return ;
	p->possible_pos = (int**)malloc(sizeof(int*) * count);
	while (++y < map->size_y)
	{
		x = -1;
		while (++x < map->size_x)
		{
			flag = ft_piece_map(map, p, x, y);
			if (flag == 1)
				i = ft_position(p, y, x, i);
		}
	}
}

int		ft_flag(int flag_1, int flag_2)
{
	if (flag_1 == 1 && flag_2 == 0)
		return (1);
	else
		return (0);
}

int		ft_piece_map(t_map *map, t_piece *p, int x, int y)
{
	int	i;
	int	j;
	int	flag_1;
	int	flag_2;

	j = -1;
	flag_1 = 0;
	flag_2 = 0;
	while (++j < p->psize_y)
	{
		i = -1;
		while (++i < p->psize_x)
			if (p->piece[j][i] == '*')
			{
				if (y + j >= map->size_y || x + i >= map->size_x)
					return (0);
				if (map->map[y + j][x + i] == map->m_p ||
					map->map[y + j][x + i] == map->m_p + 32)
					flag_1 = flag_1 + 1;
				if (map->map[y + j][x + i] == map->e_p ||
					map->map[y + j][x + i] == map->e_p + 32)
					flag_2 = flag_2 + 1;
			}
	}
	return (ft_flag(flag_1, flag_2));
}
