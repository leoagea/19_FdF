/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:57:30 by lagea             #+#    #+#             */
/*   Updated: 2024/06/11 17:33:19 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void isometric(t_data *data)
{
	int i;

	i = 0;
	while (data->arr[i])
	{
		data->arr[i]->x_proj = (data->arr[i]->x - data->arr[i]->y) * cos(0.523599);
		data->arr[i]->y_proj = (data->arr[i]->x + data->arr[i]->y) * cos(0.523599) - data->arr[i]->z;
		data->arr[i]->x_proj += WIDTH / 2;
		data->arr[i]->y_proj += HEIGHT / 2;
		// printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data->arr[i]->x_proj,data->arr[i]->y_proj, data->arr[i]->z, data->arr[i]->color);
		i++;
	}

}