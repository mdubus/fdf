/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:15:11 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/21 10:18:33 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_nb_values(char *str, int *nb_values)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((ft_isdigit(str[i])) == 0 && str[i] != '\0')
			i++;
		if ((ft_isdigit(str[i])) == 1)
		{
			while ((ft_isdigit(str[i])) == 1 && str[i] != '\0')
				i++;
			if (str[i] == ',')
			{
				i++;
				if (str[i] == '0' && str[i + 1] == 'x')
					i += 2;
				while ((have_color(str, i)) == 1)
					i++;
			}
			if (str[i] == ' ' || str[i] == '\0')
				(*nb_values)++;
		}
	}
	return (*nb_values);
}

void	check_length_errors(t_fdf_gnl **gnl, char **argv)
{
	if (((*gnl)->fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_print_error_exit(&perror, "Error ");
	}
	if ((get_next_line((*gnl)->fd, &(*gnl)->line)) < 0)
	{
		free((*gnl)->line);
		ft_print_error_exit(&ft_putendl, "Error");
	}
}

void	check_length_rest_of_file(t_fdf_gnl **gnl)
{
	int	nb_values;

	nb_values = 0;
	if ((*gnl)->ret < 0)
		ft_print_error_exit(&ft_putendl, "Error");
	if ((count_nb_values((*gnl)->line, &nb_values)) != (*gnl)->nb_values)
		ft_print_error_exit(&ft_putendl, "Found wrong line length. Exiting.");
	else
		((*gnl)->nb_lines)++;
	free((*gnl)->line);
}

void	check_length(char **argv, t_fdf_gnl **gnl)
{
	int	nb_values;

	nb_values = 0;
	check_length_errors(gnl, argv);
	(*gnl)->nb_values = count_nb_values((*gnl)->line, &nb_values);
	free((*gnl)->line);
	((*gnl)->nb_lines)++;
	while (((*gnl)->ret = get_next_line((*gnl)->fd, &(*gnl)->line)) != 0)
		check_length_rest_of_file(gnl);
}
