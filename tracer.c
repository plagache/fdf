/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:04 by plagache          #+#    #+#             */
/*   Updated: 2019/10/29 16:34:56 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
//pre scale A et B;
int		*draw_line_low(int *data, t_point A, t_point B)
{
	int x_diff;
	int y_diff;
	int D;
	int Y;
	int yi;

	x_diff = abs(A.x - B.x);
	y_diff = abs(A.y - B.y);
	yi = (y_diff < 0) ? -1 : 1;
	D = 2 * y_diff - x_diff;
	Y = A.y;
	while (A.x != B.x)
	{
		data[Y * IMG_WIDTH + A.x] = 0x00FFFFFF;
		if (D > 0)
		{
			Y = Y + yi;
			D = D - 2 * x_diff;
		}
		D = D + 2 * y_diff;
		A.x++;
	}
	return (data);
}

int		*draw_line_high(int *data, t_point A, t_point B)
{
	int x_diff;
	int y_diff;
	int D;
	int X;
	int xi;

	x_diff = abs(A.x - B.x);
	y_diff = abs(A.y - B.y);
	xi = (x_diff < 0) ? -1 : 1;
	D = 2 * x_diff - y_diff;
	X = A.x;
	while (A.y != B.y)
	{
		data[A.y * IMG_WIDTH + X] = 0x00FFFFFF;
		if (D > 0)
		{
			X = X + xi;
			D = D - 2 * y_diff;
		}
		D = D + 2 * x_diff;
		A.y++;
	}
	return (data);
}

int		scale(t_map *map)
{
	int c;

	c = 0;
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x *= IMG_WIDTH / map->x_max;
		map->tab[c].y *= IMG_HEIGHT / map->y_max;
		c++;
	}
	return (0);
}

void	which_line(int *data, t_point A, t_point B)
{
	if (abs(B.y - A.y) < abs(B.x - A.x))
	{
		if (A.x > B.x)
			draw_line_low(data, B, A);
		else
			draw_line_low(data, A, B);
	}
	else
	{
		if (A.y > B.y)
			draw_line_high(data, B, A);
		else
			draw_line_high(data, A, B);
	}
}

int		*draw(int *data, t_map *map)
{
	int	i;
	int	j;

	j = 0;
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
