/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:26 by plagache          #+#    #+#             */
/*   Updated: 2019/10/28 17:54:08 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/includes/get_next_line.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;
	int		fd;
	int		ret;

	if (ac != 2)
	{
		ft_printf("usage : ./fdf path/to/map.fdf");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (ret = read_to_list(fd, &map)) == -1
			|| data_trans(&map) == -1)
	{
		close(fd);
		ft_putendl("error");
		clean_map(&map);
		return (-1);
	}
	close(fd);
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WIN_WIDTH, WIN_HEIGHT, "ma teub");
	clean_map(&map);
	//mlx.img_ptr = mlx_new_image(mlx.init, WIN_WIDTH, WIN_HEIGHT);
	//mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	//mlx_put_image_to_window(mlx.init, mlx.window, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.window, 2, 0, &key_press, 0);
	mlx_loop(mlx.init);
	//mlx_destroy_image(mlx.init, mlx.img_ptr);
	return (0);
}
