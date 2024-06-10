/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:01 by lagea             #+#    #+#             */
/*   Updated: 2024/06/10 18:17:36 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "../mlx/mlx.h"

# define ESC 53

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

typedef struct t_data
{
	t_mlx	mlx;
	t_point **arr;
}				t_data;

/*--------------------Init--------------------*/

int dll_init(t_dll *dll);
t_dll	*dll_new(void);

/*--------------------Parse-------------------*/

void	parse_file(char *path, t_data *data);

/*-----------------Projection-----------------*/

void draw_line(int i, t_data *data, int x2, int y2);
void matrice(t_data *data, int i);

#endif