#include "minilibx/mlx.h"

int		main()
{
	void *p;
	void *w;
	void *img_ptr;
	int		size_l;
	int		bpp;
	int 	endian;
	int *img_data;
	int		count_h;
	int		count_w;


	p = mlx_init();
	count_h = -1;
	w = mlx_new_window(p, 640, 480, "mateub");
	img_ptr = mlx_new_image(p, 640, 480);
	size_l = 3200;
	bpp = 32;
	endian = 0;
	img_data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_l, &endian);

	while (++count_h < 480)
	{
		count_w = -1;
		while (++count_w < 640)
		{
			if (count_w % 2)
				/*
				   formula : [current height * max width + current width] (as you can see below)
				   */
				img_data[count_h * 640 + count_w] = 0xFFFFFF;
			else
				img_data[count_h * 480 + count_w] = 0;
		}
	}

	mlx_put_image_to_window(p, w, img_ptr, 640, 480);
	mlx_loop(p);
	return (0);
}
