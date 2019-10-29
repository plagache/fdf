/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:04 by plagache          #+#    #+#             */
/*   Updated: 2019/10/29 20:23:17 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

int		scale(t_map *map)
{
	int c;

	c = 0;
	map->scaled++;
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x *= IMG_WIDTH / (1 * map->x_max);
		map->tab[c].y *= IMG_HEIGHT / (1 * map->y_max);
		c++;
	}
	return (0);
}

int		*draw_p(int *data, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	if (map->scaled == 0)
		scale(map);
	while (j < map->y_max)
	{
		i = 0;
		while (i + 1 < map->x_max)
		{
			which_line(data, map->tab[j * map->x_max + i], map->tab[j * map->x_max + i + 1]);
			i++;
		}
		j++;
	}
	j = 0;
	while (j + 1 < map->y_max)
	{
		i = 0;
		while (i < map->x_max)
		{
			which_line(data, map->tab[j * map->x_max + i], map->tab[j * map->x_max + i + map->x_max]);
			i++;
		}
		j++;
	}
	return (data);
}
