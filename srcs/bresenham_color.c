/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:32:28 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 11:43:14 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_horiz_lines(t_param **param, int x, int y)
{
	if (x + 1 < (*param)->nb_values)
	{
		(*param)->x0 = (*param)->posx[y][x];
		(*param)->y0 = (*param)->posy[y][x];
		(*param)->x1 = (*param)->posx[y][x + 1];
		(*param)->y1 = (*param)->posy[y][x + 1];
		(*param)->color_begin = mlx_get_color_value((*param)->mlx_ptr,
				(*param)->tab_color[y][x]);
		(*param)->color_end = mlx_get_color_value((*param)->mlx_ptr,
				(*param)->tab_color[y][x + 1]);
		do_bresenham(param);
	}
}

void	print_vertical_lines(t_param **param, int x, int y)
{
	if (y + 1 < (*param)->nb_lines)
	{
		(*param)->x0 = (*param)->posx[y][x];
		(*param)->y0 = (*param)->posy[y][x];
		(*param)->x1 = (*param)->posx[y + 1][x];
		(*param)->y1 = (*param)->posy[y + 1][x];
		(*param)->color_begin = mlx_get_color_value((*param)->mlx_ptr,
				(*param)->tab_color[y][x]);
		(*param)->color_end = mlx_get_color_value((*param)->mlx_ptr,
				(*param)->tab_color[y + 1][x]);
		do_bresenham(param);
	}
}

void	print_pixel_vertical(t_param **param)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < (*param)->nb_lines)
	{
		while (x < (*param)->nb_values)
		{
			(*param)->color = mlx_get_color_value((*param)->mlx_ptr,
					(*param)->tab_color[y][x]);
			put_pixel(param, (*param)->posx[y][x], (*param)->posy[y][x]);
			print_vertical_lines(param, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_pixel(t_param **param)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < (*param)->nb_lines)
	{
		while (x < (*param)->nb_values)
		{
			(*param)->color = mlx_get_color_value((*param)->mlx_ptr,
					(*param)->tab_color[y][x]);
			put_pixel(param, (*param)->posx[y][x], (*param)->posy[y][x]);
			print_horiz_lines(param, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	print_pixel_vertical(param);
}
