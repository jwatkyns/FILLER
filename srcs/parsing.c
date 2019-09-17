/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:52:41 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/27 15:53:00 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_map(t_map *map)
{
	char	*line;
	int		y;

	get_next_line(0, &line);
	if (map->size_y == 0 && map->size_x == 0)
		ft_mapsize(map, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	y = -1;
	map->map = (char**)malloc(sizeof(char*) * map->size_y);
	while (++y < map->size_y)
	{
		get_next_line(0, &line);
		map->map[y] = (char*)malloc(sizeof(char) * map->size_x);
		map->map[y] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
	}
	ft_get_enemypos(map);
	ft_get_mypos(map);
}

void	ft_mapsize(t_map *map, char *line)
{
	int			i;
	int			temp;

	i = 0;
	map->size_y = 0;
	map->size_x = 0;
	while (line[i])
	{
		temp = 0;
		while (ft_isdigit(line[i]) == 1 && line[i])
		{
			temp += line[i] - 48;
			if (ft_isdigit(line[i + 1]) == 1)
				temp *= 10;
			i++;
		}
		if (map->size_y == 0)
			map->size_y = temp;
		else if (map->size_x == 0)
			map->size_x = temp;
		i++;
	}
}

void	ft_initialise_info(t_map *map)
{
	char	*line;

	get_next_line(0, &line);
	if (strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
		{
			map->m_p = 'X';
			map->e_p = 'O';
			map->player = 2;
		}
		if (ft_strstr(line, "p1"))
		{
			map->m_p = 'O';
			map->e_p = 'X';
			map->player = 1;
		}
	}
}

void	ft_get_psize(t_piece *p, char *line)
{
	int			i;
	int			temp;

	i = 0;
	p->psize_y = 0;
	p->psize_x = 0;
	while (line[i])
	{
		temp = 0;
		while (ft_isdigit(line[i]) == 1 && line[i])
		{
			temp += line[i] - 48;
			if (ft_isdigit(line[i + 1]) == 1)
				temp *= 10;
			i++;
		}
		if (p->psize_y == 0)
			p->psize_y = temp;
		else if (p->psize_x == 0)
			p->psize_x = temp;
		i++;
	}
}

void	ft_get_piece(t_piece *p)
{
	char	*line;
	int		y;

	get_next_line(0, &line);
	ft_get_psize(p, line);
	ft_strdel(&line);
	y = 0;
	p->piece = (char**)malloc(sizeof(char*) * p->psize_y);
	while (y < p->psize_y)
	{
		get_next_line(0, &line);
		p->piece[y] = (char*)malloc(sizeof(char) * p->psize_x);
		p->piece[y] = ft_strdup((char const *)line);
		ft_strdel(&line);
		y++;
	}
	y = -1;
}
