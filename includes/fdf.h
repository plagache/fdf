#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define IMG_WIDTH 1000
# define IMG_HEIGHT 700
# define ECHAP 53
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM 69
# define DEZOOM 78
/*
typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;
*/
typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;
typedef struct	s_map
{
	char	**board;
	t_point	*tab;
	int		x_max;
	int		y_max;
	int		scaled;
}				t_map;

typedef struct	s_mlx
{
	void	*init;
	void	*window;
	void	*img_ptr;
	int		*img_data;
	int		size_l;
	int		endian;
	int		bpp;
	t_map	*map;
}				t_mlx;


int		read_file(t_map *map, char	*path);
int		read_to_list(int fd, t_map *map, t_list *head);
int		key_press(int keycode, void *param);
int 	data_trans(t_map *map);
int		*draw_p(int *data, t_map *map);
void	vol_to_iso(t_map *map);
void	which_line(int *data, t_point A, t_point B);
void	clean_board(t_map *map);
void	clean_list(t_list *head);

#endif
