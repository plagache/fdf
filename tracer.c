/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:43:04 by plagache          #+#    #+#             */
/*   Updated: 2019/10/30 20:07:36 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

int		scale(t_map *map)
{
	int c;

	c = 0;
	if (map->scaled != 0)
		return (0);
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x *= IMG_WIDTH / (1 * map->x_max);
		map->tab[c].y *= IMG_HEIGHT / (1 * map->y_max);
		c++;
	}
	map->scaled++;
	return (0);
}

int		*draw_p(int *data, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->y_max)
	{
		i = 0;
		while (i < map->x_max)
		{
			if (i + 1 < map->x_max)
				which_line(data, map->tab_p[j * map->x_max + i], map->tab_p[j * map->x_max + i + 1]);
			if (j + 1 < map->y_max)
				which_line(data, map->tab_p[j * map->x_max + i], map->tab_p[(j + 1) * map->x_max + i]);
			i++;
		}
		j++;
	}
	return (data);
}

int		*draw_i(int *data, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->y_max)
	{
		i = 0;
		while (i < map->x_max)
		{
			if (i + 1 < map->x_max)
			{
				//which_line(data, map->tab_p[j * map->x_max + i], map->tab_p[j * map->x_max + i + 1]);
				plot_line(data, map->tab_p[j * map->x_max + i], map->tab_p[j * map->x_max + i + 1]);
			}
			if (j + 1 < map->y_max)
			{
				//which_line(data, map->tab_p[j * map->x_max + i], map->tab_p[(j + 1) * map->x_max + i]);
				plot_line(data, map->tab_p[j * map->x_max + i], map->tab_p[(j + 1) * map->x_max + i]);
			}
			i++;
		}
			printf("i%i j%i\n", i, j);
		j++;
	}
	return (data);
}

void	draw_iso(t_mlx *mlx, t_map *map)
{
	mlx->img_ptr = mlx_new_image(mlx->init, IMG_WIDTH, IMG_HEIGHT);
	mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
				&mlx->size_l, &mlx->endian);
//	scale(map);
	rotate(map, mlx->delta);
	draw_i(mlx->img_data, map);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img_ptr, 200, 200);
	mlx_destroy_image(mlx->init, mlx->img_ptr);
}
