/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:45 by lagea             #+#    #+#             */
/*   Updated: 2024/06/20 17:45:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int init_data(t_data *data)
{
	data->arr = NULL;
	return 0;
}

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

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

	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	create_image(&data);
	
	mlx_loop_hook(data.mlx, hook, data.mlx);
	
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	// int i = 0;
	// int j;
	// while (i < data.map.len_y)
	// {
	// 	j = 0;
	// 	while (j < data.map.len_x)
	// 	{
	// 		printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data.arr[i][j]->x,data.arr[i][j]->y, data.arr[i][j]->z, data.arr[i][j]->color);
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	return EXIT_SUCCESS;
}
