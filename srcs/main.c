/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:13:53 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/21 10:24:54 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	do_fdf(t_param **param)
{
	(*param)->mlx_ptr = mlx_init();
	(*param)->win = mlx_new_window((*param)->mlx_ptr, WIDTH_W, HEIGHT_W,
			"mlx 42");
	print_image(param);
	mlx_mouse_hook((*param)->win, &mouse_events, param);
	mlx_hook((*param)->win, KeyPress, KeyPressMask, &key_press, param);
	mlx_hook((*param)->win, KeyRelease, KeyReleaseMask, &key_release, param);
	mlx_hook((*param)->win, DestroyNotify, (1L << 17), &red_cross, param);
	mlx_loop_hook((*param)->mlx_ptr, &loop_key, param);
	mlx_loop((*param)->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_param			*param;

	param = NULL;
	if (argc != 2)
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	else
	{
		init_param(&param);
		fdf_parsing(&param, argv, &param->z, &param->tab_color);
		if (param->nb_lines != 0 && param->nb_values != 0)
			do_fdf(&param);
		else
			ft_print_error_exit(&ft_putendl, "Error : empty file");
	}
	return (0);
}
