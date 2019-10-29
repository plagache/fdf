/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:45 by plagache          #+#    #+#             */
/*   Updated: 2019/10/29 20:21:15 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

void		expose_hook(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->init, IMG_WIDTH, IMG_HEIGHT);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_l, &mlx->endian);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img_ptr, 100, 100);
	mlx_destroy_image(mlx->init, mlx->img_ptr);
}

int		key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == ECHAP)
	{
		mlx_destroy_image(mlx->init, mlx->img_ptr);
		exit(0);
	}
	if (keycode == RIGHT)
	{
		draw_p(mlx->img_data, mlx->map);
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->img_ptr, 100, 100);
		return (0);
	}
	//	if (keycode == LEFT)
	//		draw_i(mlx->img_data ,mlx->map);
	expose_hook(mlx);
	return (0);
}
