/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:16:27 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/26 14:00:50 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_struct(t_map *map, t_piece *p)
{
	map->map = NULL;
	map->player = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->e_p = 0;
	map->m_p = 0;
	map->ep_size = 0;
	map->mp_size = 0;
	map->touch = 0;
	map->ret = 0;
	p->piece = NULL;
	p->possible_pos = NULL;
	p->pp_size = 1;
}

int		main(void)
{
	t_map	*map;
	t_piece	*p;

	map = (t_map *)malloc(sizeof(*map));
	p = (t_piece *)malloc(sizeof(*p));
	ft_init_struct(map, p);
	ft_initialise_info(map);
	while (1)
	{
		ft_get_map(map);
		ft_get_piece(p);
		ft_get_positions(map, p);
		if (p->pp_size == 0)
		{
			ft_print_end();
			break ;
		}
		ft_get_enemy_info(map, p);
		ft_print_final(p);
	}
	free(map);
	free(p);
	return (0);
}
