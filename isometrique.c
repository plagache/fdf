/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:30:33 by plagache          #+#    #+#             */
/*   Updated: 2019/10/29 19:02:53 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"

//mettre les CTE en valeurs pour les faire moduler
//
void	vol_to_iso(t_map *map)
{
	t_point	iso;
	int		c;
	int		x_min;
	int		y_min;

	c = 0;
	while (c < map->x_max * map->y_max)
	{
		iso.x = 2 * map->tab[c].x - 2 * map->tab[c].y;
		iso.y = 2 * map->tab[c].z + map->tab[c].x + map->tab[c].y;
		map->tab[c].x = iso.x;
		map->tab[c].y = iso.y;
		c++;
	}
	c = 0;
	while (c < map->x_max * map->y_max)
	{
		x_min = (x_min > map->tab[c].x) ? map->tab[c].x : x_min;
		y_min = (y_min > map->tab[c].y) ? map->tab[c].y : y_min;
		c++;
	}
	c = 0;
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x += abs(x_min);
		map->tab[c].y += abs(y_min);
		c++;
	}
}
/*
void	vol_to_iso(t_map *map)
{
	t_point	iso;
	int		c;
	int		x_min;
	int		y_min;

	c = 0;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab[c].x - map->tab[c].z) / sqrt(2);
		iso.y = (map->tab[c].z + map->tab[c].x + 2 * map->tab[c].y) / sqrt(6);
		map->tab[c].x = iso.x;
		map->tab[c].y = iso.y;
		c++;
	}
	c = 0;
	while (c < map->x_max * map->y_max)
	{
		x_min = (x_min > map->tab[c].x) ? map->tab[c].x : x_min;
		y_min = (y_min > map->tab[c].y) ? map->tab[c].y : y_min;
		c++;
	}
	c = 0;
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x += abs(x_min);
		map->tab[c].y += abs(y_min);
		c++;
	}
}
*/
