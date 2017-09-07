/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:04:10 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 12:58:51 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_bresenham(t_bresenham *bre, int x1, int y1)
{
	bre->dx = x1 - bre->x;
	bre->dy = y1 - bre->y;
	bre->i = 1;
	bre->xinc = (bre->dx > 0) ? 1 : -1;
	bre->yinc = (bre->dy > 0) ? 1 : -1;
	bre->dx = (bre->dx > 0) ? bre->dx : -bre->dx;
	bre->dy = (bre->dy > 0) ? bre->dy : -bre->dy;
}

void	bresenham_case1(t_bresenham *bre, t_param **param)
{
	bre->cumul = bre->dx / 2;
	while (bre->i <= bre->dx)
	{
		bre->x += bre->xinc;
		bre->cumul += bre->dy;
		if (bre->cumul >= bre->dx)
		{
			bre->cumul -= bre->dx;
			bre->y += bre->yinc;
		}
		if ((*param)->color_begin != (*param)->color_end)
			(*param)->color = mlx_get_color_value((*param)->mlx_ptr, 0xFFFFFF);
		put_pixel(param, bre->x, bre->y);
		(bre->i)++;
	}
}

void	bresenham_case2(t_bresenham *bre, t_param **param)
{
	int	j;

	j = 0;
	bre->cumul = bre->dx / 2;
	bre->cumul = bre->dy / 2;
	while (bre->i <= bre->dy)
	{
		bre->y += bre->yinc;
		bre->cumul += bre->dx;
		if (bre->cumul >= bre->dy)
		{
			bre->cumul -= bre->dy;
			bre->x += bre->xinc;
		}
		if ((*param)->color_begin != (*param)->color_end)
			(*param)->color = mlx_get_color_value((*param)->mlx_ptr, 0xFFFFFF);
		put_pixel(param, bre->x, bre->y);
		(bre->i)++;
	}
}

void	do_bresenham(t_param **param)
{
	t_bresenham		bre;

	bre.x = (*param)->x0;
	bre.y = (*param)->y0;
	init_bresenham(&bre, (*param)->x1, (*param)->y1);
	put_pixel(param, bre.x, bre.y);
	if (bre.dx > bre.dy)
		bresenham_case1(&bre, param);
	else
		bresenham_case2(&bre, param);
}
