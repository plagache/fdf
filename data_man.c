/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:18:32 by plagache          #+#    #+#             */
/*   Updated: 2019/10/29 12:19:01 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"

int		alloc_tab(t_map *map, t_point *pt)
{
	int	c;

	pt->y = 0;
	pt->x = 0;
	c = 0;
	while (map->board[pt->y])
		pt->y++;
	while (map->board[0][c])
	{
		while (map->board[0][c] && ft_isdigit(map->board[0][c]) == 1)
			c++;
		pt->x++;
		while (map->board[0][c] && ft_isdigit(map->board[0][c]) == 0)
			c++;
	}
	if (!(map->tab = (t_point*)malloc(sizeof(t_point) * (pt->y * pt->x) + 1)))
		return (0);
	map->tab[pt->y * pt->x] = NULL;
	return (1);
}

int		same_length(t_map *map)
{
	int c;
	size_t len;

	c = 0;
	len = ft_strlen(map->board[0]);
	while (map->board[c])
	{
		if (ft_strlen(map->board[c]) != len)
			return (-1);
		c++;
	}
	return (0);
}

int 	data_trans(t_map *map)
{
	t_point	pt;

	if (same_length(map) == -1)
		return (-1);
	if (alloc_tab(map, &pt) == 0);
		return (-1);
	return (0);
}
