/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:01 by lagea             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/07 15:15:47 by lagea            ###   ########.fr       */
=======
/*   Updated: 2024/06/07 12:55:43 by lagea            ###   ########.fr       */
>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "../mlx/mlx.h"

# define ESC 53

<<<<<<< HEAD
=======
typedef struct s_col
{
	t_dll *dll;
	struct s_col *next;
}				t_col;

>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
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
}				t_point;

typedef struct t_data
{
	t_mlx	mlx;
}				t_data;

/*--------------------Init--------------------*/

<<<<<<< HEAD
int dll_init(t_dll *dll);
t_dll	*dll_new(void);
=======

>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9

/*--------------------Parse-------------------*/

void parse_file(char *path);

#endif