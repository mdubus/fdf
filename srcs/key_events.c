/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:21:54 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 17:22:28 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_press(int keycode, t_param **param)
{
	if (keycode == ESC)
	{
		free(*param);
		exit(1);
	}
	else if (keycode >= 0 && keycode <= 255)
		(*param)->keyflag[keycode] = 1;
	if (keycode == 49)
	{
		(*param)->iso = ((*param)->iso == 1) ? 0 : 1;
		print_image(param);
	}
	return (0);
}

int		key_release(int keycode, t_param **param)
{
	if (keycode >= 0 && keycode <= 255)
		(*param)->keyflag[keycode] = 0;
	return (0);
}

void	change_height(t_param **param)
{
	if ((*param)->keyflag[MORE] == 1)
	{
		(*param)->height += 1;
		print_image(param);
	}
	if ((*param)->keyflag[LESS] == 1)
	{
		(*param)->height -= 1;
		print_image(param);
	}
}

void	move_keys(t_param **param)
{
	if ((*param)->keyflag[LEFT] == 1)
	{
		(*param)->offx -= ((*param)->iso == 1) ? 10 : 0;
		(*param)->midx -= ((*param)->iso == 0) ? 10 : 0;
		print_image(param);
	}
	if ((*param)->keyflag[RIGHT] == 1)
	{
		(*param)->offx += ((*param)->iso == 1) ? 10 : 0;
		(*param)->midx += ((*param)->iso == 0) ? 10 : 0;
		print_image(param);
	}
	if ((*param)->keyflag[TOP] == 1)
	{
		(*param)->offy -= ((*param)->iso == 1) ? 10 : 0;
		(*param)->midy -= ((*param)->iso == 0) ? 10 : 0;
		print_image(param);
	}
	if ((*param)->keyflag[BOTTOM] == 1)
	{
		(*param)->offy += ((*param)->iso == 1) ? 10 : 0;
		(*param)->midy += ((*param)->iso == 0) ? 10 : 0;
		print_image(param);
	}
	change_height(param);
}

int		loop_key(t_param **param)
{
	if ((*param)->keyflag[PLUS] == 1)
	{
		(*param)->space += 1;
		print_image(param);
	}
	if ((*param)->keyflag[MINUS] == 1)
	{
		(*param)->space -= 1;
		print_image(param);
	}
	move_keys(param);
	return (0);
}
