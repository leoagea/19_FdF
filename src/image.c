/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:55:13 by lagea             #+#    #+#             */
/*   Updated: 2024/06/12 17:47:08 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define D_GREEN 65280

void	put_pixel_image(int x,int y, char *str, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int len;

	len = WIDTH; 
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	// printf("r : %d | g : %d | b : %d\n", r, g,b);

	str[(x * 4) + (len * 4 * y)] = b;
	str[(x * 4) + (len * 4 * y) + 1] = g;
	str[(x * 4) + (len * 4 * y) + 2] = r;
	str[(x * 4) + (len * 4 * y) + 3] = 0;
}

// static void			print_square(int left_corner_x, int left_corner_y, int len_in_pixels, t_data *data)
// {
// 	int y;
// 	int x;
// 	int			y_stop;
// 	int			x_stop;

// 	x_stop = left_corner_x + len_in_pixels;
// 	y_stop = left_corner_y + len_in_pixels;
// 	y = left_corner_y;

// 	while (y != y_stop)
// 	{
// 		x = left_corner_x;
// 		while (x != x_stop)
// 		{
// 			put_pixel_image(x, y, data->img.img_ptr, D_GREEN);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void image(t_data *data)
{
	int i;

	i = 0;
	data->img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->img.img_ptr = mlx_get_data_addr(data->img.img, &data->img.bits, &data->img.size_line, &data->img.endian);
	// print_square(10,10, 50, data);
	// draw_map(data);
	isometric(&data);
	int j = data->map.len_x * data->map.len_y;
	while (i < j)
	{
		// printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data->arr[i]->x_proj,data->arr[i]->y_proj, data->arr[i]->z, data->arr[i]->color);
		// put_pixel_image(data->arr[i]->x_proj ,data->arr[i]->y_proj, data->img.img_ptr, data->arr[i]->color);
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, data->arr[i]->x_proj, data->arr[i]->y_proj, data->arr[i]->color);
		i++;
	}
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0,0);
}