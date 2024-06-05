/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:45 by lagea             #+#    #+#             */
/*   Updated: 2024/06/05 17:37:57 by lagea            ###   ########.fr       */
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
	data = NULL;
	return 0;
}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	// t_data data;

	// // init_data(&data);
	// data.mlx.mlx = mlx_init();
	// data.mlx.win = mlx_new_window(data.mlx.mlx, 1000, 1000, "FdF");
	// mlx_hook(data.mlx.win, 17, 0, &destroy, &data);
	// mlx_hook(data.mlx.win, 2, 0, &keypress, &data);
	// mlx_loop(data.mlx.mlx);

	if (ac == 2)
		parse_file(av[1]);
	else
		exit(EXIT_FAILURE);
	return 0;
}
