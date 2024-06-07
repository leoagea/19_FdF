/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:20:50 by lagea             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/07 17:27:18 by lagea            ###   ########.fr       */
=======
/*   Updated: 2024/06/07 12:55:39 by lagea            ###   ########.fr       */
>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

<<<<<<< HEAD
static int	count_nbr(char const *s, char c)
{
	int	index;
	int	nbr_words;

	index = 0;
	nbr_words = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != '\0')
			nbr_words++;
		while (s[index] != c && s[index])
			index++;
	}
	return (nbr_words);
}

static void	fill_in_dll(t_dll *dll, char *line, int row)
{
	int		i;
	int		nbr;
	int count;
	char	*color;
	char	**value;
	char *check;

	i = -1;
	value = ft_split(line, ' ');
	check = ft_strrchr(line, ' ');
	count = count_nbr(line, ' ');
	if (*(check + 1) == '\n')
		count -= 1;
	while (++i < count)
	{
		nbr = ft_atoi(value[i]);
		color = ft_strchr(value[i], ',');
		free(value[i]);
		dll_insert_tail(nbr, dll);
		dll->tail->col = i;
		dll->tail->line = row;
		if (color != NULL)
			dll->tail->color = ft_atoi_base(color + 3, "0123456789ABCDEF");
	}
}

void	parse_file(char *path)
{
	int		fd;
	int		row;
	char	*gnl;
	t_dll	*line;
	t_node	*current;
	t_point **arr = NULL;
	

	line = NULL;
=======
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
	
>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n", strerror(errno));
	}
	gnl = get_next_line(fd);
	if (!gnl)
		return ;
	if (dll_init(line) == 0)
		return ;
	line = dll_new();
	row = 0;
	while (gnl != NULL)
	{
		fill_in_dll(line, gnl, row);
		free(gnl);
		gnl = get_next_line(fd);
		row++;
	}
	// current = line->head;
	// while (current != NULL)
	// {
	// 	printf("col : %d, line : %d, value : %d, color : %d\n", current->col,current->line, current->value,current->color);
	// 	current = current->next;
	// }
	// printf("atoi base : %d\n",ft_atoi_base("FFFFFF", "0123456789ABCDEF"));
	arr = malloc(sizeof(t_point *) * (((line->tail->line + 1) * line->tail->col) + 1));
	int j = (line->tail->line + 1) * line->tail->col;
	int i = 0;
	current = line->head;
	while (i < j)
	{
		arr[i] = malloc(sizeof(t_point));
		arr[i]->x =  current->col;
		arr[i]->y =  current->line;
		arr[i]->z =  current->value;
		arr[i]->color =  current->color;
		// printf("x : %d, y : %d , z : %d, color : %d\n", arr[i]->x,arr[i]->y, arr[i]->z, arr[i]->color);
		i++;
		current = current->next;
	}
	// free(gnl);
	// close(fd);
}
