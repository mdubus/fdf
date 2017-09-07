/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:15:24 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/18 12:02:21 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_events(int button, int x, int y, t_param **param)
{
	(void)x;
	(void)y;
	(*param)->space += (button == 5) ? 1 : 0;
	(*param)->space -= (button == 4) ? 1 : 0;
	if (button == 7)
	{
		(*param)->offx -= ((*param)->iso == 1) ? 10 : 0;
		(*param)->midx -= ((*param)->iso == 0) ? 10 : 0;
	}
	if (button == 6)
	{
		(*param)->offx += ((*param)->iso == 1) ? 10 : 0;
		(*param)->midx += ((*param)->iso == 0) ? 10 : 0;
	}
	print_image(param);
	return (0);
}

int		red_cross(t_param **param)
{
	free(*param);
	exit(1);
}
