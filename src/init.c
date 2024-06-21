/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:40 by lagea             #+#    #+#             */
/*   Updated: 2024/06/21 16:51:31 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int dll_init(t_dll *dll)
{
	dll = malloc(sizeof(t_dll));
	if (!dll)
		return 0;
	dll->head = NULL;
	dll->tail = NULL;
	return 1;
}

t_dll	*dll_new(void)
{
	t_dll	*new;

	new = malloc(sizeof(t_dll));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

void init_zoom(t_data *data)
{
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
			j++;
		}
		i++;
	}
}