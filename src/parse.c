/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/06/04 16:08:48 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int dll_init(t_dll *dll)
{
	dll = malloc(sizeof(t_dll));
	if (!dll)
		return 0;
	dll->head = NULL;
	dll->tail = NULL;
	return 1;
}

static int col_init(t_col *col)
{
	col = malloc(sizeof(t_col));
	if (!col)
		return 0;
	col->dll = NULL;
	col->next = NULL;
	return 1;
}
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

static void fill_in_col(t_col *col, t_dll *line)
{
	col->dll = line;
	col = col->next;
}

void parse_file(char *path)
{
	int fd;
	char *gnl;
	t_dll line;
	t_col *col;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
	}
	gnl = get_next_line(fd);
	if (!gnl)
		return ;
	if (dll_init(&line) == 0 || dll_init(&col) == 0)
		return ;
	while (gnl != NULL)
	{
		fill_in_col(col, &line);
		free(gnl);
	}
	col = NULL;
	while (col)
	{
		/* code */
	}
	
}
