/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:45 by plagache          #+#    #+#             */
/*   Updated: 2019/10/30 12:22:55 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

void	escape(t_mlx *mlx)
{
	t_map *map;

	map = mlx->map;
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_ptr);
	mlx_destroy_window(mlx->init, mlx->window);
	if (map->tab)
		free(map->tab);
}

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
		escape(mlx);
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
	return (0);
}
