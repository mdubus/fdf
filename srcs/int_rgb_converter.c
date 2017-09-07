/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_rgb_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:21:16 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 16:21:49 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	int_to_rgb(t_param **param)
{
	(*param)->red = ((*param)->color >> 16) & 255;
	(*param)->green = ((*param)->color >> 8) & 255;
	(*param)->blue = (*param)->color & 255;
}

void	rgb_to_int(t_param **param)
{
	(*param)->color = (unsigned int)(*param)->red << 16 |
		(unsigned int)(*param)->green << 8 | (unsigned int)(*param)->blue;
}
