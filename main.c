#include "includes/fdf.h"
#include "libft/includes/get_next_line.h"
#include <stdio.h>

void	dispay(char **board)
{
	int c;

	c = 0;
	while (board[c])
	{
		ft_printf("%s\n", board[c]);
	}
}

int		parsing(int fd, t_map map)
{
	int ret;
	char **tmp;

	while ((ret = get_next_line(fd, tmp)) > 0)
	{

	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	int		fd;
	int		ret;

	if (ac != 2)
	{
		ft_printf("usage : ./fdf path/to/map.fdf");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (ret = parsing(fd, map)) == -1)
	{
		close(fd);
		ft_putendl("error");
		return (1);
	}
	close(fd);
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WIN_WIDTH, WIN_HEIGHT, "ma teub");
	mlx.img.img_ptr = mlx_new_image(mlx.init, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.img_data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.init);
	return (0);
}
