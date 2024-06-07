/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/06/07 12:55:39 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static void fill_in_col(t_dll *dll, t_col *col)
// {
	
// 	// dll_print_forward(dll);
// 	col->dll = dll;
// 	col = col->next;
// }

void parse_file(char *path)
{
	int fd;
	char *gnl;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
	}
	gnl = get_next_line(fd);
	if (!gnl)
		return ;
	while (gnl != NULL)
	{
		free(gnl);
		// fill_in_col(line, col);
		gnl = get_next_line(fd);
	}
	// free(gnl);
	// close(fd);
}
