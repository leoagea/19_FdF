/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:45 by lagea             #+#    #+#             */
/*   Updated: 2024/06/12 16:43:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int destroy(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	free(data->mlx.mlx);
	exit(0);
	return 0;
}

int keypress(int keysym, t_data *data)
{
	// printf("key : %d\n",keysym);
	if (keysym == ESC)
		destroy(data);
	return 0;
}

int init_data(t_data *data)
{
	data->arr = NULL;
	return 0;
}

// static test(t_data *data)
// {
// 	int i=0;
// 	while (data->arr[i])
// 	{
// 		if (data->arr[i] != 0)
// 			test_projection(i, &data, data->arr[i]->x, data->arr[i]->y);
// 		i++;
// 	}
// }

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_data data;

	init_data(&data);
	
	if (ac == 2)
		parse_file(av[1], &data);
	else
		exit(EXIT_FAILURE);
	// data.arr = malloc(sizeof(t_point *) * 10);
	// for (int i = 0; i < 8; i++)
	// {
	// 	data.arr[i] = malloc(sizeof(t_point));
	// 	printf("Enter the value of x and y and z: ");
	// 	scanf("%d%d%d", &data.arr[i]->x, &data.arr[i]->y,&data.arr[i]->z);
	// }
	
	// for (int i = 0; i < 9; i++)
	// {
	// 	matrice(&data, i);
	// 	printf("\n");
	// 	printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data.arr[i]->x_proj,data.arr[i]->y_proj, data.arr[i]->z, data.arr[i]->color);
	// }

	data.mlx.mlx = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.mlx, 1920, 1080, "FdF");
	mlx_hook(data.mlx.win, 17, 0, &destroy, &data);
	mlx_hook(data.mlx.win, 2, 0, &keypress, &data);
	// t_point *a = malloc(sizeof(t_point));
	// t_point *b = malloc(sizeof(t_point));
	// a->x = 0;
	// a->y = 0;
	// b->x = 750;
	// b->y = 750;
	// printf("x : %d, y : %d\n",data.arr[0]->x, data.arr[0]->y);
	// printf("x : %d, y : %d\n",data.arr[35]->x, data.arr[35]->y);
	// draw_line_bresenham(data.arr[0], data.arr[35], &data);
	// draw_line(0, &data, 0, 0);
	// draw_line(0, &data, 800, 800);

	image(&data);
	// draw_map(&data);
	mlx_loop(data.mlx.mlx);
	return 0;
}
