/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:10:42 by lagea             #+#    #+#             */
/*   Updated: 2024/06/21 14:27:56 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void create_menu(t_data *data)
{
	if (!(data->menu = mlx_new_image(data->mlx, 300, HEIGHT)))
	{
		mlx_close_window(data->mlx);
		error();
	}
	ft_memset(data->menu->pixels, 128, data->menu->width * data->menu->height * sizeof(int32_t));
	mlx_image_to_window(data->mlx, data->menu, 0, 0);
	mlx_put_string(data->mlx, "Settings :", 100, 10);
	mlx_put_string(data->mlx, "Zoom: + / -", 15, 50);
	mlx_put_string(data->mlx, "Move: Arrows or WASD", 15 , 80);
	mlx_put_string(data->mlx, "Flatten: < / >", 15, 110);
	mlx_put_string(data->mlx, "Projection", 15, 150);
	mlx_put_string(data->mlx, "Iso: I", 30, 180);
	mlx_put_string(data->mlx, "Parallel: P", 30, 210);
}
