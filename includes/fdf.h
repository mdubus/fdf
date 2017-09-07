/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:46:36 by mdubus            #+#    #+#             */
/*   Updated: 2017/05/21 10:20:17 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "X.h"
# include "../libft/includes/libft.h"
# include <math.h>

/*
** stdio pour perror
*/

# include <stdio.h>

# define WIDTH_W 800
# define HEIGHT_W 800
# define SPACING 30
# define PLUS 69
# define MINUS 78
# define TOP 126
# define BOTTOM 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define LESS 43
# define MORE 47

typedef struct		s_param
{
	void			*mlx_ptr;
	void			*win;
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				s_l;
	int				endian;
	int				space;
	int				nb_lines;
	int				nb_values;
	int				startx;
	int				starty;
	int				midx;
	int				midy;
	int				x;
	int				y;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				blue;
	int				green;
	int				red;
	int				iso;
	int				offx;
	int				offy;
	int				height;
	unsigned int	color;
	unsigned int	color_begin;
	unsigned int	color_end;
	int				**z;
	int				**tab_color;
	int				**posx;
	int				**posy;
	int				keyflag[256];
}					t_param;

typedef struct		s_fdf_gnl
{
	char			*line;
	char			*buffer;
	char			*arg;
	int				fd;
	int				ret;
	int				nb_values;
	int				nb_lines;
}					t_fdf_gnl;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_bresenham;

/*
** FDF
*/

/*
** PROJECTION
*/
void				put_flat(t_param **param);
void				flat_top_left(t_param **param);
void				flat_top_right(t_param **param);
void				flat_bot_left(t_param **param);
void				flat_bot_right(t_param **param);
void				init_flat_top_left(t_param **param);
void				init_flat_top_right(t_param **param);
void				init_flat_bot_left(t_param **param);
void				init_flat_bot_right(t_param **param);
void				flat_to_iso_projection(t_param **param);
void				flat_to_iso_projection2(t_param **param, int *x, int y);
void				init_posxy(t_param **param);

/*
** PRINT SOMETHING
*/
void				init_param(t_param **param);
void				init_param2(t_param **param);
void				put_pixel(t_param **param, int x, int y);
void				background_color_fdf(t_param **param, int col);
void				print_image(t_param **param);
void				print_pixel(t_param **param);
void				print_pixel_vertical(t_param **param);
void				print_horiz_lines(t_param **param, int x, int y);
void				print_vertical_lines(t_param **param, int x, int y);
void				int_to_rgb(t_param **param);
void				rgb_to_int(t_param **param);
void				print_color(int ***color, t_fdf_gnl *gnl);
void				print_tab(int ***tab, int ***color, t_fdf_gnl *gnl);
void				print_text(t_param **param);

/*
** EVENTS
*/
int					key_function(int keycode, t_param **param);
int					my_mouse_funct(int keycode, t_param **param);
int					my_expose_funct(int keycode, t_param **param);
int					red_cross(t_param **param);
int					key_press(int keycode, t_param **param);
int					mouse_events(int button, int x, int y, t_param **param);
int					key_release(int keycode, t_param **param);
int					loop_key(t_param **param);
void				move_keys(t_param **param);
void				change_height(t_param **param);

/*
** BRESENHAM
*/
void				do_bresenham(t_param **param);
void				init_bresenham(t_bresenham *bre, int x1, int y1);
void				bresenham_case1(t_bresenham *bre, t_param **param);
void				bresenham_case2(t_bresenham *bre, t_param **param);
void				bresenham_put_color_horiz(t_param **param);
void				bresenham_color_vertical(t_param **param);

/*
** PARSING
*/

void				fdf_parsing(t_param **param, char **argv, int ***tab,
					int ***tab_color);
void				init_struct(t_fdf_gnl **gnl);
void				check_name(char **argv);
void				check_type_of_file(char **argv);
void				free_struct(t_fdf_gnl **gnl);
int					count_nb_values(char *str, int *nb_values);
int					have_color(char *str, int y);
void				check_length_errors(t_fdf_gnl **gnl, char **argv);
void				check_length(char **argv, t_fdf_gnl **gnl);
void				check_length_rest_of_file(t_fdf_gnl **gnl);
void				fill_tab(int ***tab, t_fdf_gnl *gnl, int ***tab_color);
void				split_temp(char ****temp, int ***tab, int ***tab_color,
					t_fdf_gnl *gnl);
void				temp_in_color(int i, int j, int ***tab_color,
					char ****temp);
void				do_malloc1(int ***tab, int ***tab_color, t_fdf_gnl *gnl);
void				do_malloc2(int ***tab, int ***tab_color, t_fdf_gnl *gnl,
					int i);
void				free_temp(char ****temp);

#endif
