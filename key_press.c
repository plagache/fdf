/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:45 by plagache          #+#    #+#             */
/*   Updated: 2019/10/30 16:14:41 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

/*
** drwa_func(mlx, draw_code)
** clear_window
** new_image
** get_addr
** sub_draw"i/p"
** put_image
** destroy_image
*/
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
		draw_iso(mlx, mlx->map);
		return (0);
	}
	if (keycode == DOWN)
	{
		mlx->delta -= 1;
		if (mlx->delta < 0)
			mlx->delta = 360;
		draw_iso(mlx, mlx->map);
		return (0);
	}
	if (keycode == RIGHT)
	{
		//draw_p(mlx->img_data, mlx->map);
		ft_printf("para");
		return (0);
	}
	if (keycode == LEFT)
	{
		draw_iso(mlx ,mlx->map);
		return (0);
	}
	return (0);
}
