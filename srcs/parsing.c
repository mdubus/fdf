/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:40:57 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 19:14:22 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_temp(char ****temp)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*temp)[i] != NULL)
	{
		while ((*temp)[i][j] != NULL)
			free((*temp)[i][j++]);
		free((*temp)[i]);
		i++;
		j = 0;
	}
	free((*temp));
}

void	fill_tab(int ***tab, t_fdf_gnl *gnl, int ***color)
{
	int			i;
	int			j;
	char		***temp;

	i = 0;
	j = 0;
	if ((temp = (char ***)malloc(sizeof(char **) *
					(unsigned long)(gnl->nb_lines + 1))) == NULL)
		ft_print_error_exit(&ft_putendl, "Malloc Error");
	if ((gnl->fd = open(gnl->arg, O_RDONLY)) < 0)
		ft_print_error_exit(&perror, "Error ");
	while ((gnl->ret = get_next_line(gnl->fd, &(gnl)->line)) != 0)
	{
		temp[i] = ft_strsplit(gnl->line, ' ');
		i++;
	}
	temp[i] = NULL;
	split_temp(&temp, tab, color, gnl);
	free_temp(&temp);
}

void	fdf_parsing(t_param **param, char **argv, int ***tab, int ***color)
{
	t_fdf_gnl	*gnl;

	init_struct(&gnl);
	gnl->arg = ft_strdup(argv[1]);
	check_type_of_file(argv);
	check_name(argv);
	check_length(argv, &gnl);
	close(gnl->fd);
	fill_tab(tab, gnl, color);
	(*param)->nb_lines = gnl->nb_lines;
	(*param)->nb_values = gnl->nb_values;
	free(gnl);
}
