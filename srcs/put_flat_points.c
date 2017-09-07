/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flat_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:07:44 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 19:35:59 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	flat_top_left(t_param **param)
{
	int		x;
	int		y;

	init_flat_top_left(param);
	x = (*param)->x;
	y = (*param)->y;
	(*param)->posx[y][x] = (*param)->startx;
	(*param)->posy[y][x--] = (*param)->starty;
	while (y >= 0)
	{
		while (x >= 0)
		{
			(*param)->posx[y][x] = (*param)->posx[y][x + 1] - (*param)->space;
			(*param)->posy[y][x] = (*param)->posy[y][x + 1];
			x--;
		}
		x = (*param)->x;
		y--;
		if (y >= 0)
		{
			(*param)->posx[y][x] = (*param)->posx[y + 1][x];
			(*param)->posy[y][x] = (*param)->posy[y + 1][x] - (*param)->space;
		}
		x--;
	}
}

void	flat_top_right(t_param **param)
{
	int		x;
	int		y;

	init_flat_top_right(param);
	x = (*param)->x;
	y = (*param)->y;
	(*param)->posx[y][x] = (*param)->startx;
	(*param)->posy[y][x++] = (*param)->starty;
	while (y >= 0)
	{
		while (x < (*param)->nb_values)
		{
			(*param)->posx[y][x] = (*param)->posx[y][x - 1] + (*param)->space;
			(*param)->posy[y][x] = (*param)->posy[y][x - 1];
			x++;
		}
		x = (*param)->x;
		y--;
		if (y >= 0)
		{
			(*param)->posx[y][x] = (*param)->posx[y + 1][x];
			(*param)->posy[y][x] = (*param)->posy[y + 1][x] - (*param)->space;
		}
		x++;
	}
}

void	flat_bot_left(t_param **param)
{
	int		x;
	int		y;

	init_flat_bot_left(param);
	x = (*param)->x;
	y = (*param)->y;
	(*param)->posx[y][x] = (*param)->startx;
	(*param)->posy[y][x--] = (*param)->starty;
	while (y < (*param)->nb_lines)
	{
		while (x >= 0)
		{
			(*param)->posx[y][x] = (*param)->posx[y][x + 1] - (*param)->space;
			(*param)->posy[y][x] = (*param)->posy[y][x + 1];
			x--;
		}
		x = (*param)->x;
		y++;
		if (y < (*param)->nb_lines)
		{
			(*param)->posx[y][x] = (*param)->posx[y - 1][x];
			(*param)->posy[y][x] = (*param)->posy[y - 1][x] + (*param)->space;
		}
		x--;
	}
}

void	flat_bot_right(t_param **param)
{
	int		x;
	int		y;

	init_flat_bot_right(param);
	x = (*param)->x;
	y = (*param)->y;
	(*param)->posx[y][x] = (*param)->startx;
	(*param)->posy[y][x++] = (*param)->starty;
	while (y < (*param)->nb_lines)
	{
		while (x < (*param)->nb_values)
		{
			(*param)->posx[y][x] = (*param)->posx[y][x - 1] + (*param)->space;
			(*param)->posy[y][x] = (*param)->posy[y][x - 1];
			x++;
		}
		x = (*param)->x;
		y++;
		if (y < (*param)->nb_lines)
		{
			(*param)->posx[y][x] = (*param)->posx[y - 1][x];
			(*param)->posy[y][x] = (*param)->posy[y - 1][x] + (*param)->space;
		}
		x++;
	}
}
