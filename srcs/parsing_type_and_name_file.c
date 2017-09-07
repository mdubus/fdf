/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_name_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:14:34 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/20 18:35:46 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_name(char **argv)
{
	char		*name;
	size_t		length;

	name = NULL;
	length = 0;
	name = argv[1];
	length = ft_strlen_secure(name);
	if (length <= 4 ||
			((name[length - 1] != 'f' || name[length - 2] != 'd' ||
			name[length - 3] != 'f' || name[length - 4] != '.')))
		ft_print_error_exit(&ft_putendl, "Error : not a valid file");
}

void	check_type_of_file(char **argv)
{
	t_fdf_gnl	*gnl;

	init_struct(&gnl);
	if ((gnl->fd = open(argv[1], O_RDONLY)) < 0)
		ft_print_error_exit(&perror, "Error ");
	if ((read(gnl->fd, gnl->buffer, BUFF_SIZE)) < 0)
		ft_print_error_exit(&perror, "Error ");
	close(gnl->fd);
	free_struct(&gnl);
}
