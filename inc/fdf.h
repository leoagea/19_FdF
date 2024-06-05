/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:09:01 by lagea             #+#    #+#             */
/*   Updated: 2024/06/05 13:42:47 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "../mlx/mlx.h"

# define ESC 53

typedef struct s_col
{
	t_dll *dll;
	struct s_col *next;
}				t_col;

typedef struct s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct t_data
{
	t_mlx	mlx;
}				t_data;

/*--------------------Init--------------------*/

int dll_init(t_dll *dll);
int col_init(t_col *col);

#endif