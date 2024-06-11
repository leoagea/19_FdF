/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:55:13 by lagea             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:33 by lagea            ###   ########.fr       */
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
	data->img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->img.img_ptr = mlx_get_data_addr(data->img.img, &data->img.bits, &data->img.size_line, &data->img.endian);
	// print_square(10,10, 50, data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0,0);
}