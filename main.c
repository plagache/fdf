/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:26 by plagache          #+#    #+#             */
/*   Updated: 2019/10/31 12:12:34 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	get_mlx(t_mlx *mlx, t_map *map)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx->map = map;
	mlx->delta = 30;
	mlx->alpha = 30;
	mlx_hook(mlx->window, 2, 0, &key_press, mlx);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	if (ac != 2)
	{
		ft_putendl("usage : ./fdf path/to/map.fdf");
		return (-1);
	}
	if (read_file(&map, av[1]) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	get_mlx(&mlx, &map);
	draw_x(&mlx, &map);
	mlx_loop(mlx.init);
	return (0);
}
