/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/06/05 17:49:43 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void fill_in_dll(t_dll *dll, char *line)
{
	int i;
	int nbr;
	char **value;

	i = 0;
	value = ft_split(line, ' ');
	while (value [i] != NULL)
	{
		nbr = ft_atoi(value[i]);
		free(value[i]);
		dll_insert_tail(nbr, dll);
		i++;
	}
}

static void fill_in_col(t_dll *dll, t_col *col)
{
	dll_print_forward(dll);
	col->dll = dll;
	// col = col->next;
}

void parse_file(char *path)
{
	int fd;
	char *gnl;
	t_dll *line;
	t_col *col;
	

	col = NULL;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
	}
	gnl = get_next_line(fd);
	if (!gnl)
		return ;
	if (dll_init(line) == 0 || col_init(col) == 0)
		return ;
	int i = 0;
	while (/*gnl != NULL*/i < 1)
	{
		line = dll_new();
		fill_in_dll(line, gnl);
		free(gnl);
		fill_in_col(line, col);
		gnl = get_next_line(fd);
		i++;
	}
	// free(gnl);
	// close(fd);
}
