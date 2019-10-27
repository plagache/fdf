#include "minilibx/mlx.h"

int		main()
{
	void *p;
	void *d;
	int y;
	int x;

	x = 0;
	p = mlx_init();
	d = mlx_new_window(p, 640, 480, "mateub");
	while(x < 320)
	{
		y = 0;
		while(y < 240)
		{
			mlx_pixel_put(p, d, x, y, 0x00ffffff);
			y++;
		}
		x++;
	}
	mlx_loop(p);
	return (0);
}
