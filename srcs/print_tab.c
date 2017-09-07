/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:51:00 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/16 12:53:25 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_color(int ***color, t_fdf_gnl *gnl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*color)[i] != NULL)
	{
		while (j < gnl->nb_values)
		{
			ft_putnbr((*color)[i][j++]);
			ft_putstr("  ");
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
	ft_putchar('\n');
}

void	print_tab(int ***tab, int ***color, t_fdf_gnl *gnl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*tab)[i] != NULL)
	{
		while (j < gnl->nb_values)
		{
			ft_putnbr((*tab)[i][j++]);
			ft_putstr("  ");
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
	ft_putchar('\n');
	print_color(color, gnl);
}
