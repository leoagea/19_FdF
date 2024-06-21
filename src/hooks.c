/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:32:17 by lagea             #+#    #+#             */
/*   Updated: 2024/06/21 16:50:12 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void zoom(t_data *data, int value)
{
	printf("In zoom\n");
	data->map.zoom += value;
	// printf("zoom : %d",data->map.zoom);
	isometric_projection(data);
	// put_image(data);
}

void translation(t_data *data,bool dir, int value)
{
	int j;
	int i = 0;
	while (i < data->map.len_y)
	{
		j = 0;
		while (j < data->map.len_x)
		{
			if (dir)
				data->arr[i][j]->x += value;
			else
				data->arr[i][j]->y += value;
			j++;
		}
		i++;
	}
	isometric_projection(data);
}