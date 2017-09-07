/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:16:35 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 18:33:52 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct(t_fdf_gnl **gnl)
{
	if ((*gnl = (t_fdf_gnl*)malloc(sizeof(t_fdf_gnl) * BUFF_SIZE)) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc error");
	(*gnl)->line = NULL;
	(*gnl)->fd = -1;
	(*gnl)->ret = -1;
	(*gnl)->buffer = NULL;
	if (((*gnl)->buffer = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc error");
	(*gnl)->arg = NULL;
	(*gnl)->nb_values = 0;
	(*gnl)->nb_lines = 0;
}

void	init_param2(t_param **param)
{
	(*param)->midx = WIDTH_W / 2;
	(*param)->midy = HEIGHT_W / 2;
	(*param)->iso = 1;
	(*param)->offx = 0;
	(*param)->offy = 0;
	ft_bzero((*param)->keyflag, 256);
	(*param)->x0 = 0;
	(*param)->x1 = 0;
	(*param)->y0 = 0;
	(*param)->y1 = 0;
	(*param)->color_begin = 0;
	(*param)->color_end = 0;
	(*param)->height = 0;
}

void	init_param(t_param **param)
{
	if (((*param) = (t_param*)malloc(sizeof(t_param))) == NULL)
		ft_print_error_exit(&ft_putendl, "Error");
	(*param)->mlx_ptr = NULL;
	(*param)->win = NULL;
	(*param)->img = NULL;
	(*param)->img_ptr = NULL;
	(*param)->bpp = -1;
	(*param)->s_l = -1;
	(*param)->endian = -1;
	(*param)->color = 0;
	(*param)->space = SPACING;
	(*param)->nb_lines = 0;
	(*param)->nb_values = 0;
	(*param)->tab_color = NULL;
	(*param)->z = NULL;
	(*param)->startx = 0;
	(*param)->starty = 0;
	(*param)->posx = NULL;
	(*param)->posy = NULL;
	(*param)->x = 0;
	(*param)->y = 0;
	(*param)->blue = 0;
	(*param)->green = 0;
	(*param)->red = 0;
	init_param2(param);
}

void	init_posxy(t_param **param)
{
	int		i;

	i = 0;
	if (((*param)->posx = (int **)malloc(sizeof(int *) *
					(unsigned long)((*param)->nb_lines + 1))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
	if (((*param)->posy = (int **)malloc(sizeof(int *) *
					(unsigned long)((*param)->nb_lines + 1))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
	(*param)->posx[(*param)->nb_lines] = NULL;
	(*param)->posy[(*param)->nb_lines] = NULL;
	while (i < (*param)->nb_lines)
	{
		if ((((*param)->posx)[i] = (int *)malloc(sizeof(int) *
						(unsigned long)((*param)->nb_values))) == NULL)
			ft_print_error_exit(&ft_putendl, "Malloc Error");
		if ((((*param)->posy)[i] = (int *)malloc(sizeof(int) *
						(unsigned long)((*param)->nb_values))) == NULL)
			ft_print_error_exit(&ft_putendl, "Malloc Error");
		i++;
	}
}
