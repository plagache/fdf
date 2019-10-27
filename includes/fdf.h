#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define ECHAP 53
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM 69
# define DEZOOM 78

typedef struct	s_map
{
	char 	**board;
	int		x;
	int 	y;
}				t_map;

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_data;
	int		size_l;
	int		endian;
	int		bpp;
}				t_img;

typedef struct	s_mlx
{
	void	*init;
	void	*window;
	t_img	img;
}				t_mlx;

#endif
