/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:41:33 by lagea             #+#    #+#             */
/*   Updated: 2024/06/12 16:09:29 by lagea            ###   ########.fr       */
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
		// mlx_pixel_put(data->mlx.mlx, data->mlx.win, data->arr[i]->x_proj,data->arr[i]->y_proj,data->arr[i]->color);
		put_pixel_image(data->arr[i]->x_proj, data->arr[i]->y_proj, data->img.img_ptr, data->arr[i]->color);
		data->arr[i]->x_proj += dx;
		data->arr[i]->y_proj += dy;
		j++;
	}
}

void draw_line_bresenham(t_point *a, t_point *b, t_data *data)
{
	int dx;
	int dy;
	dx = b->x - a->x;
	dy = b->y - a->y;
	if(abs(dx) > abs(dy))
		slope_less_then_one(dx, dy, data,a);
	else
		slope_bigger_then_one(dx, dy, data,a);
}

void slope_less_then_one(int dx, int dy, t_data *data, t_point *a)
{
	int p;
	int j;
	
	j = -1;
	p = 2 * abs(dy) - abs(dx);
	// pixel_put(data, data->arr[i]->x, data->arr[i]->y);
	put_pixel_image(a->x, a->y, data->img.img_ptr, a->color);
	while (++j < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		// pixel_put(data, data->arr[i]->x, data->arr[i]->y);
		put_pixel_image(a->x, a->y, data->img.img_ptr, a->color);
	}
}

void slope_bigger_then_one(int dx, int dy, t_data *data, t_point *a)
{
	int p;
	int j;
	
	j = -1;
	p = 2 * abs(dx) - abs(dy);
	// pixel_put(data, data->arr[i]->x, data->arr[i]->y);
	put_pixel_image(a->x, a->y, data->img.img_ptr, a->color);
	while (++j < abs(dy))
	{
		if (dy > 0)
			a->y += 1;
		else	
			a->y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dy);
		}
		put_pixel_image(a->x, a->y, data->img.img_ptr, a->color);
		// pixel_put(data, data->arr[i]->x, data->arr[i]->y);
	}
}

void pixel_put(t_data *data, int x, int y)
{
	mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, 0xFFFFFF);
}

void draw_map(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->arr[i])
	{
		data->arr[i]->x *= ZOOM;
		data->arr[i]->y *= ZOOM;
		data->arr[i]->z *= ZOOM;
		data->arr[i]->x += WIDTH / 2;
		data->arr[i]->y += HEIGHT / 2;
		i++;
	}
	i = 0;
	while (i < data->map.len_y)
	{
		j = 0 ;
		while (j < data->map.len_x)
		{
			if (j != 18 && data->arr[(i * 19) + (j + 1)])
				draw_line_bresenham(data->arr[(i * 19) + j], data->arr[(i * 19) + (j + 1)],data);
			if (data->arr[((i + 1) * 19) + j])
				draw_line_bresenham(data->arr[(i * 19) + j], data->arr[((i + 1) * 19) + j], data);
			j++;
		}
		i++;
	}
}
