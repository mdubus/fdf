/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_temp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:52:09 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/16 12:53:57 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	temp_in_color(int i, int j, int ***color, char ****temp)
{
	int		k;
	char	*temp2;

	k = 0;
	temp2 = NULL;
	if ((ft_strchr((*temp)[i][j], ',')) == 0)
		(*color)[i][j] = ft_atoi_base("FFFFFF", 16);
	else
	{
		while ((*temp)[i][j][k] != ',')
			k++;
		k++;
		if ((*temp)[i][j][k] == '0' && ((*temp)[i][j][k + 1] == 'x' ||
					(*temp)[i][j][k + 1] == 'X'))
			k += 2;
		temp2 = ft_strsub((*temp)[i][j], (unsigned int)k,
				ft_strlen_secure((*temp)[i][j]) - (unsigned long)k);
		(*color)[i][j] = ft_atoi_base(temp2, 16);
		free(temp2);
	}
}

void	do_malloc1(int ***tab, int ***color, t_fdf_gnl *gnl)
{
	if ((*tab = (int **)malloc(sizeof(int *) *
					(unsigned long)(gnl->nb_lines + 1))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
	if ((*color = (int **)malloc(sizeof(int *) *
					(unsigned long)(gnl->nb_lines + 1))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
}

void	do_malloc2(int ***tab, int ***color, t_fdf_gnl *gnl, int i)
{
	if (((*color)[i] = (int *)malloc(sizeof(int) *
					(unsigned long)(gnl->nb_values))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
	if (((*tab)[i] = (int *)malloc(sizeof(int) *
					(unsigned long)(gnl->nb_values))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
}

void	split_temp(char ****temp, int ***tab, int ***color, t_fdf_gnl *gnl)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	do_malloc1(tab, color, gnl);
	while ((*temp)[i] != NULL)
	{
		do_malloc2(tab, color, gnl, i);
		while ((*temp)[i][j] != NULL)
		{
			(*tab)[i][j] = ft_atoi((*temp)[i][j]);
			temp_in_color(i, j, color, temp);
			j++;
		}
		j = 0;
		i++;
	}
	(*tab)[i] = NULL;
	(*color)[i] = NULL;
}
