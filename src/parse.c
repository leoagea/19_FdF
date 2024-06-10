/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/06/10 17:28:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

static void fill_in_arr(t_dll *line, t_data *data)
{
	t_node	*current;

	data->arr = malloc(sizeof(t_point *) * (((line->tail->line + 1) * line->tail->col) + 1));
	int j = (line->tail->line + 1) * (line->tail->col + 1);
	printf("y : %d, x : %d\n", line->tail->line + 1, line->tail->col + 1);
	printf("j : %d\n\n",j);
	int i = 0;
	current = line->head;
	while (i < j)
	{
		data->arr[i] = malloc(sizeof(t_point));
		data->arr[i]->x =  current->col;
		data->arr[i]->y =  current->line;
		data->arr[i]->z =  current->value;
		data->arr[i]->color =  current->color;
		printf("i : %d, x : %d, y : %d , z : %d, color : %d\n", i, data->arr[i]->x,data->arr[i]->y, data->arr[i]->z, data->arr[i]->color);
		i++;
		current = current->next;
	}
}

void	parse_file(char *path, t_data *data)
{
	int		fd;
	int		row;
	char	*gnl;
	t_dll	*line;
	(void) data;
	

	line = NULL;
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
	free(gnl);
	// current = line->head;
	// while (current != NULL)
	// {
	// 	printf("col : %d, line : %d, value : %d, color : %d\n", current->col,current->line, current->value,current->color);
	// 	current = current->next;
	// }
	// printf("atoi base : %d\n",ft_atoi_base("FFFFFF", "0123456789ABCDEF"));
	fill_in_arr(line, data);
	// close(fd);
}
