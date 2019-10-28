/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:18:32 by plagache          #+#    #+#             */
/*   Updated: 2019/10/28 17:54:16 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"

int		calc_x_y(t_map *map)
{
	int x;
	int y;
	int	c;

	y = 0;
	x = 0;
	c = 0;
	while (map->board[y])
		y++;
	if (!(map->tab = (int**)malloc(sizeof(int*) * (y + 1))))
		return (0);
	map->tab[y] = NULL;
	y = 0;
	while (map->board[y][x])
	{
		while (map->board[y][x] && ft_isdigit(map->board[y][x]) == 1)
			x++;
		c++;
		while (map->board[y][x] && ft_isdigit(map->board[y][x]) == 0)
			x++;
	}
	return (c);
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
	if (same_length(map) == -1)
		return (-1);
	calc_x_y(map);
	return (0);
}
