/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 10:20:48 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/21 10:21:15 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	background_color_fdf(t_param **param, int col)
{
	int	x;
	int	y;

	x = 0 - (*param)->offx;
	y = 0 - (*param)->offy;
	(*param)->color = mlx_get_color_value((*param)->mlx_ptr, col);
	while (y + (*param)->offy < HEIGHT_W)
	{
		while (x + (*param)->offx < WIDTH_W)
		{
			put_pixel(param, x, y);
			x++;
		}
		x = 0 - (*param)->offx;
		y++;
	}
}

void	print_text(t_param **param)
{
	mlx_string_put((*param)->mlx_ptr, (*param)->win, 20, 10,
			(int)(*param)->color, "mdubus");
	mlx_string_put((*param)->mlx_ptr, (*param)->win, 20, 50,
			(int)(*param)->color, "Projection : space");
	mlx_string_put((*param)->mlx_ptr, (*param)->win, 20, 70,
			(int)(*param)->color, "Move : arrows");
	mlx_string_put((*param)->mlx_ptr, (*param)->win, 20, 90,
			(int)(*param)->color, "Zoom : + - scroll");
	mlx_string_put((*param)->mlx_ptr, (*param)->win, 20, 110,
			(int)(*param)->color, "Height : < >");
}

void	print_image(t_param **param)
{
	if ((*param)->nb_lines != 0 && (*param)->nb_values != 0)
	{
		if (((*param)->img_ptr = mlx_new_image((*param)->mlx_ptr,
						WIDTH_W, HEIGHT_W)) == NULL)
			ft_print_error_exit(&ft_putendl, "Error");
		(*param)->img = mlx_get_data_addr((*param)->img_ptr, &(*param)->bpp,
				&(*param)->s_l, &(*param)->endian);
		background_color_fdf(param, 0x112233);
		(*param)->color = mlx_get_color_value((*param)->mlx_ptr, 0xFFFFFF);
		put_flat(param);
		mlx_put_image_to_window((*param)->mlx_ptr, (*param)->win,
				(*param)->img_ptr, 0, 0);
		(*param)->color = mlx_get_color_value((*param)->mlx_ptr, 0xFFFFFF);
		print_text(param);
		mlx_destroy_image((*param)->mlx_ptr, (*param)->img_ptr);
	}
	else
		ft_print_error_exit(&ft_putendl, "Error : empty file");
}
