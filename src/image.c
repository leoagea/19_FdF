/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:14:17 by lagea             #+#    #+#             */
/*   Updated: 2024/06/21 13:13:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void isometric_projection(t_data *data)
{
	data->map.zoom = (WIDTH / data->map.len_x) / 3;
	int j;
	int i = 0;
	while (i < data->map.len_y)
	{
		j = 0;
		while (j < data->map.len_x)
		{
			data->arr[i][j]->x *= data->map.zoom;
			data->arr[i][j]->y *= data->map.zoom;
			data->arr[i][j]->z *= data->map.zoom;
			data->arr[i][j]->x_proj = (data->arr[i][j]->x - data->arr[i][j]->y) * cos(0.523599);
			data->arr[i][j]->y_proj = (data->arr[i][j]->x + data->arr[i][j]->y) * cos(0.523599) - data->arr[i][j]->z;
			data->arr[i][j]->x_proj += WIDTH / 2;
			data->arr[i][j]->y_proj += HEIGHT / 2;
			// printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data->arr[i][j]->x_proj,data->arr[i][j]->y_proj, data->arr[i][j]->z, data->arr[i][j]->color);
			j++;
		}
		i++;
	}
}

void create_image(t_data *data)
{
	int i = 0;
	int j;
	if (!(data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(data->mlx);
		error();
	}
	isometric_projection(data);
	ft_memset(data->image->pixels, 16, data->image->width * data->image->height * sizeof(int32_t));
	while (i < data->map.len_y)
	{
		j = 0;
		while (j < data->map.len_x)
		{
			if (data->arr[i][j]->x_proj < WIDTH && data->arr[i][j]->y_proj < HEIGHT)
				mlx_put_pixel(data->image, data->arr[i][j]->x_proj, data->arr[i][j]->y_proj, data->arr[i][j]->color);
			j++;
		}
		i++;
	}
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}
