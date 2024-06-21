/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:45 by lagea             #+#    #+#             */
/*   Updated: 2024/06/21 16:51:00 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int init_data(t_data *data)
{
	data->arr = NULL;
	return 0;
}

void hook(void *param)
{
	t_data *data;

    data = (t_data *)param;
	// mlx_t* mlx = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP)){
		zoom(data, 5);
		usleep(75000);
		printf("Test UP\n");}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)){
		zoom(data, -5);
		usleep(75000);
		printf("Test DOWN\n");}
}

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_data *data;

    data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS){
		zoom(data, -5);
		printf("Test DOWN\n");}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS){
		zoom(data, 5);
		printf("Test UP\n");}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS){
		translation(data, true, 5);
		printf("Test W\n");}

}

void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
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
		error();
	data.map.zoom = (WIDTH/ data.map.len_x) / 3;
	printf("zoom : %d", data.map.zoom);
	init_zoom(&data);
	create_image(&data);
	create_menu(&data);
	
	mlx_key_hook(data.mlx, &key_hook, &data);
	
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
