/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:01 by lagea             #+#    #+#             */
/*   Updated: 2024/06/12 16:45:39 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "../mlx/mlx.h"

# define ESC 53
# define HEIGHT 1080
# define WIDTH 1920
# define ZOOM 20

typedef struct s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
	int x_proj;
	int y_proj;
}				t_point;

typedef struct s_map
{
	int	len_x;
	int len_y;
	int zoom;
}				t_map;

typedef struct s_img
{
	void *img;
	char *img_ptr;
	int bits;
	int size_line;
	int endian;
}				t_img;

typedef struct s_data
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	t_point **arr;
}				t_data;

/*--------------------Init--------------------*/

int dll_init(t_dll *dll);
t_dll	*dll_new(void);

/*--------------------Parse-------------------*/

void	parse_file(char *path, t_data *data);

/*-----------------Projection-----------------*/

void draw_line(int i, t_data *data, int x2, int y2);
void draw_line_bresenham(t_point *a, t_point *b, t_data *data);
void slope_less_then_one(int dx, int dy, t_data *data, t_point *a);
void slope_bigger_then_one(int dx, int dy, t_data *data, t_point *a);
void pixel_put(t_data *data, int x, int y);
void draw_map(t_data *data);

/*------------------Isometric------------------*/

void isometric(t_data **data);

/*--------------------Image--------------------*/

void	put_pixel_image(int x,int y, char *str, int color);
void image(t_data *data);

#endif