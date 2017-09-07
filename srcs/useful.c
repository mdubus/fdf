/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:13:13 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/21 10:21:20 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_struct(t_fdf_gnl **gnl)
{
	free((*gnl)->buffer);
	free(*gnl);
}

int		have_color(char *str, int y)
{
	if (((ft_isdigit(str[y])) == 1 || ((str[y] >= 'a' && str[y] <= 'f')) ||
				((str[y] >= 'A' && str[y] <= 'F'))) && (str[y] != '\0'))
		return (1);
	else
		return (0);
}

void	put_pixel(t_param **param, int x, int y)
{
	int					somme;

	somme = 0;
	if ((x + (*param)->offx > 0) && (x + (*param)->offx) < WIDTH_W &&
			(y + (*param)->offy) > 0 && (y + (*param)->offy) < HEIGHT_W)
	{
		somme = (int)(y + (*param)->offy) * WIDTH_W * 4 +
			(x + (*param)->offx) * 4;
		int_to_rgb(param);
		(*param)->img[somme] = (char)(*param)->blue;
		(*param)->img[somme + 1] = (char)(*param)->green;
		(*param)->img[somme + 2] = (char)(*param)->red;
	}
}
