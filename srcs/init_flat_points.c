/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flat_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:25:48 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/16 19:35:08 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_flat_top_left(t_param **param)
{
	if ((*param)->nb_values % 2 != 0)
	{
		(*param)->startx = (*param)->midx;
		(*param)->x = ((*param)->nb_values / 2);
	}
	else
	{
		(*param)->startx = (*param)->midx - ((*param)->space / 2);
		(*param)->x = ((*param)->nb_values / 2) - 1;
	}
	if ((*param)->nb_lines % 2 != 0)
	{
		(*param)->y = (*param)->nb_lines / 2;
		(*param)->starty = (*param)->midy;
	}
	else
	{
		(*param)->y = ((*param)->nb_lines / 2) - 1;
		(*param)->starty = (*param)->midy - ((*param)->space / 2);
	}
}

void	init_flat_top_right(t_param **param)
{
	(*param)->x = (*param)->nb_values / 2;
	if ((*param)->nb_values % 2 != 0)
		(*param)->startx = (*param)->midx;
	else
		(*param)->startx = (*param)->midx + ((*param)->space / 2);
	if ((*param)->nb_lines % 2 != 0)
	{
		(*param)->y = ((*param)->nb_lines / 2);
		(*param)->starty = (*param)->midy;
	}
	else
	{
		(*param)->y = ((*param)->nb_lines / 2) - 1;
		(*param)->starty = (*param)->midy - ((*param)->space / 2);
	}
}

void	init_flat_bot_left(t_param **param)
{
	if ((*param)->nb_values % 2 != 0)
	{
		(*param)->x = (*param)->nb_values / 2;
		(*param)->startx = (*param)->midx;
	}
	else
	{
		(*param)->x = ((*param)->nb_values / 2) - 1;
		(*param)->startx = (*param)->midx - ((*param)->space / 2);
	}
	(*param)->y = (*param)->nb_lines / 2;
	if ((*param)->nb_lines % 2 != 0)
		(*param)->starty = (*param)->midy;
	else
		(*param)->starty = (*param)->midy + ((*param)->space / 2);
}

void	init_flat_bot_right(t_param **param)
{
	(*param)->x = (*param)->nb_values / 2;
	(*param)->y = (*param)->nb_lines / 2;
	if ((*param)->nb_values % 2 != 0)
		(*param)->startx = (*param)->midx;
	else
		(*param)->startx = (*param)->midx + ((*param)->space / 2);
	if ((*param)->nb_lines % 2 != 0)
		(*param)->starty = (*param)->midy;
	else
		(*param)->starty = (*param)->midy + ((*param)->space / 2);
}
