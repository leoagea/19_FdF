/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:33 by lagea             #+#    #+#             */
/*   Updated: 2024/06/10 18:40:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#include <stdio.h>

void draw_line(int i, t_data *data, int x2, int y2)
{
	int dx;
	int dy;
	int step;

	// printf("Enter the value of x1 and y1 : ");
	// scanf("%d%d", &data->arr[i]->x, &data->arr[i]->y);
	// // printf("Enter the value of x2 and y2: ");
	// // scanf("%d%d",&x2,&y2);
	// printf("x : %d, y : %d\n",data->arr[i]->x, data->arr[i]->y);
	
	dx = abs(x2 - data->arr[i]->x);
	dy = abs(y2 - data->arr[i]->y);

	if (dx >= dy)
		step = dx;
	else
		step = dy;
	dx = dx / step;		
	dy = dy / step;
	data->arr[i]->x_proj = data->arr[i]->x;
	data->arr[i]->y_proj = data->arr[i]->y;
	int j = 1;
	while (j <= step)
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, data->arr[i]->x_proj + 10,data->arr[i]->y_proj+  10,data->arr[i]->color);
		data->arr[i]->x_proj += dx;
		data->arr[i]->y_proj += dy;
		j++;
	}
}

void matrice(t_data *data, int i)
{
	data->arr[i]->x_proj = (data->arr[i]->x * cos(45)) - (data->arr[i]->y * sin(45));
	data->arr[i]->y_proj = ((sqrt(3) / 3) * ((data->arr[i]->x * sin(45)) + (data->arr[i]->y * cos(45))) - ((sqrt(6) / 3) * data->arr[i]->y)); 
}