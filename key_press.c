/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:45 by plagache          #+#    #+#             */
/*   Updated: 2019/10/31 12:16:32 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == ECHAP)
	{
		exit(0);
	}
	if (keycode == UP)
	{
		mlx->delta += 1;
		if (mlx->delta > 360)
			mlx->delta = 0;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (keycode == DOWN)
	{
		mlx->delta -= 1;
		if (mlx->delta < 0)
			mlx->delta = 360;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (keycode == RIGHT)
	{
		mlx->alpha -= 1;
		if (mlx->alpha < 0)
			mlx->alpha = 360;
		draw_y(mlx, mlx->map);
		return (0);
	}
	if (keycode == LEFT)
	{
		mlx->alpha -= 1;
		if (mlx->alpha < 0)
			mlx->alpha = 360;
		draw_y(mlx, mlx->map);
		return (0);
	}
	return (0);
}
