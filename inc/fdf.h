/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:01 by lagea             #+#    #+#             */
/*   Updated: 2024/06/18 18:54:42 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

# define ESC 53
# define HEIGHT 1080
# define WIDTH 1920
# define ZOOM 20

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

typedef struct s_data
{
	mlx_t	*mlx;
	t_map	map;
	t_point ***arr;
	mlx_image_t* image;
}				t_data;

/*--------------------Init--------------------*/

int dll_init(t_dll *dll);
t_dll	*dll_new(void);

/*--------------------Parse-------------------*/

void	parse_file(char *path, t_data *data);

/*--------------------Image--------------------*/

void create_image(t_data *data);
void isometric_projection(t_data *data);

#endif