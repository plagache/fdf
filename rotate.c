/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:30:33 by plagache          #+#    #+#             */
/*   Updated: 2019/10/31 12:18:45 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	rotate_x(t_map *map, double delta)
{
	int			c;
	t_double	iso;

	c = 0;
	delta = (M_PI * delta) / 180;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab[c].x * 1) + (map->tab[c].y * 0) + (map->tab[c].z * 0);
		iso.y = (map->tab[c].x * 0) + (map->tab[c].y * cos(delta))
			+ (map->tab[c].z * -sin(delta));
		iso.z = (map->tab[c].x * 0) + (map->tab[c].y * sin(delta))
			+ (map->tab[c].z * cos(delta));
		map->tab_p[c].x = iso.x * 3;
		map->tab_p[c].y = iso.y * 3;
		c++;
	}
}

void	rotate_y(t_map *map, double alpha)
{
	int			c;
	t_double	iso;

	c = 0;
	alpha = (M_PI * alpha) / 180;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab[c].x * cos(alpha)) + (map->tab[c].y * 0) 
			+ (map->tab[c].z * sin(alpha));
		iso.y = (map->tab[c].x * 0) + (map->tab[c].y * 1) + (map->tab[c].z * 0);
		iso.z = (map->tab[c].x * -sin(alpha)) + (map->tab[c].y * 0)
			+ (map->tab[c].z * cos(alpha));
		map->tab_p[c].x = iso.x * 3;
		map->tab_p[c].y = iso.y * 3;
		c++;
	}
}
