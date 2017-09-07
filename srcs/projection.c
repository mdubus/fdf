/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:26:49 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 11:38:32 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	flat_to_iso_projection2(t_param **param, int *x, int y)
{
	int	tempx;
	int	tempy;
	int	temp_height;

	tempx = 0;
	tempy = 0;
	temp_height = 0;
	tempx = ((*param)->posx[y][*x] - (*param)->posy[y][*x]) + (*param)->midx;
	tempy = ((*param)->posx[y][*x] + (*param)->posy[y][*x]) / 2;
	if ((*param)->z[y][*x] != 0)
	{
		temp_height = (*param)->z[y][*x] + (*param)->height;
		if ((*param)->z[y][*x] > 0)
			tempy -= temp_height * ((*param)->space / 2);
		else if ((*param)->z[y][*x] < 0)
			tempy += temp_height * ((*param)->space / 2) * -1;
	}
	(*param)->posx[y][*x] = tempx;
	(*param)->posy[y][*x] = tempy;
	(*x)++;
}

void	flat_to_iso_projection(t_param **param)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < (*param)->nb_lines)
	{
		while (x < (*param)->nb_values)
			flat_to_iso_projection2(param, &x, y);
		y++;
		x = 0;
	}
}

void	put_flat(t_param **param)
{
	init_posxy(param);
	flat_top_left(param);
	flat_top_right(param);
	flat_bot_left(param);
	flat_bot_right(param);
	if ((*param)->iso == 1)
		flat_to_iso_projection(param);
	print_pixel(param);
}
