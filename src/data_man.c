/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:18:32 by plagache          #+#    #+#             */
/*   Updated: 2019/11/04 11:36:18 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		alloc_tab(t_map *map, t_point *pt)
{
	int	c;

	pt->y = 0;
	pt->x = 0;
	c = 0;
	while (map->board[(int)pt->y])
		pt->y++;
	while (map->board[0][c])
	{
		if (c == 0 && map->board[0][c] == '-')
			c++;
		while (map->board[0][c] && ft_isdigit(map->board[0][c]) == 1)
			c++;
		pt->x++;
		while (map->board[0][c] && ft_isdigit(map->board[0][c]) == 0)
			c++;
	}
	if (!(map->tab = (t_point*)malloc(sizeof(t_point) * (pt->y * pt->x))))
		return (0);
	if (!(map->tab_p = (t_point*)malloc(sizeof(t_point) * (pt->y * pt->x))))
	{
		free(map->tab);
		return (0);
	}
	return (1);
}

int		ft_isnbr(char c)
{
	if (c == '-' || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

void	fill_tabp(t_map *map, t_point *pt)
{
	int c;

	c = 0;
	while (c < pt->y * pt->x)
	{
		map->tab_p[c] = map->tab[c];
		c++;
	}
}

void	fill_tab(t_map *map, t_point *pt)
{
	int	x;
	int	y;
	int c;

	y = 0;
	while (y < pt->y)
	{
		x = 0;
		c = 0;
		while (x < pt->x)
		{
			(map->tab[(int)(y * pt->x + x)]).x = x;
			(map->tab[(int)(y * pt->x + x)]).y = y;
			(map->tab[(int)(y * pt->x + x)]).z = atoi(map->board[y] + c);
			while (map->board[y][c] && ft_isnbr(map->board[y][c]) == 1)
				c++;
			while (map->board[y][c] && ft_isnbr(map->board[y][c]) == 0)
				c++;
			x++;
		}
		y++;
	}
}

int		data_trans(t_map *map)
{
	t_point	pt;

	if (alloc_tab(map, &pt) == 0)
		return (-1);
	fill_tab(map, &pt);
	fill_tabp(map, &pt);
	clean_board(map);
	map->x_max = pt.x;
	map->y_max = pt.y;
	map->scaled = 0;
	return (0);
}
