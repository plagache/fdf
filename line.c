/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:47:07 by plagache          #+#    #+#             */
/*   Updated: 2019/10/30 20:10:07 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx_macos/mlx.h"
#include "libft/includes/ft_printf.h"

int		*draw_line_low(int *data, t_point A, t_point B)
{
	int x_diff;
	int y_diff;
	int D;
	int Y;
	int yi;

	x_diff = abs(A.x - B.x);
	y_diff = abs(A.y - B.y);
	yi = (y_diff < 0) ? -1 : 1;
	D = 2 * y_diff - x_diff;
	Y = A.y;
	while (A.x <= B.x)
	{
	//	printf("A.x=%i||B.x=%i\nA.y=%i||B.y=%i\n\n", A.x, B.x, A.y, B.y);
		if ((Y * IMG_WIDTH + A.x) >= 0 && (Y * IMG_WIDTH + A.x) < IMG_WIDTH * IMG_HEIGHT)
			data[Y * IMG_WIDTH + A.x] = 0x00FFFFFF;
		if (D > 0)
		{
			Y = Y + yi;
			D = D - 2 * x_diff;
		}
		D = D + 2 * y_diff;
		A.x++;
	}
	return (data);
}

int		*draw_line_high(int *data, t_point A, t_point B)
{
	int x_diff;
	int y_diff;
	int D;
	int X;
	int xi;

	x_diff = abs(A.x - B.x);
	y_diff = abs(A.y - B.y);
	xi = (x_diff < 0) ? -1 : 1;
	D = 2 * x_diff - y_diff;
	X = A.x;
	while (A.y <= B.y)
	{
		if (((A.y * IMG_WIDTH + X) >= 0) && (A.y * IMG_WIDTH + X) < IMG_WIDTH * IMG_HEIGHT)
			data[A.y * IMG_WIDTH + X] = 0x00FFFFFF;
		if (D > 0)
		{
			X = X + xi;
			D = D - 2 * y_diff;
		}
		D = D + 2 * x_diff;
		A.y++;
	}
	return (data);
}

void	which_line(int *data, t_point A, t_point B)
{
//	printf("A.x=%i||B.x=%i\nA.y=%i||B.y=%i\n\n", A.x, B.x, A.y, B.y);

	if (abs(B.y - A.y) < abs(B.x - A.x))
	{
		if (A.x > B.x)
		{
			draw_line_low(data, B, A);
		}
		else
		{
			draw_line_low(data, A, B);
		}
	}
	else
	{
		if (A.y > B.y)
		{
			draw_line_high(data, B, A);
		}
		else
		{
			draw_line_high(data, A, B);
		}
	}
}

void	plot_line(int *data, t_point A, t_point B)
{
	int x_diff;
	int	x_sign;
	int y_diff;
	int	y_sign;
	int	err;

	x_diff = abs(A.x - B.x);
	x_sign = A.x < B.x ? 1 : -1;
	y_diff = abs(A.y - B.y);
	y_sign = A.y < B.y ? 1 : -1;
	err	= x_diff + y_diff;
	while (A.x != B.x && A.y != B.y)
	{
		printf("to\n");
		if (((A.y * IMG_WIDTH + A.x) >= 0) && (A.y * IMG_WIDTH + A.x) < IMG_WIDTH * IMG_HEIGHT)
		data[A.y * IMG_WIDTH + A.x] = 0x00FFFFFF;
//		if (A.x == B.x && A.y == B.y)
//			exit(0);
		if ((2 * err) >= y_diff)
		{
			err += y_diff;
			A.x += x_sign;
		}
		if ((2 * err) <= x_diff)
		{
			err += x_diff;
			A.y += y_diff;
		}
	}
}
