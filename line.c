/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:47:07 by plagache          #+#    #+#             */
/*   Updated: 2019/10/31 11:24:06 by plagache         ###   ########.fr       */
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

	x_diff = B.x - A.x;
	y_diff = B.y - A.y;
	yi = (y_diff < 0) ? -1 : 1;
	y_diff = abs(y_diff);
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

	x_diff = B.x - A.x;
	y_diff = B.y - A.y;
	xi = (x_diff < 0) ? -1 : 1;
	x_diff = abs(x_diff);
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
