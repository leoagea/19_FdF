/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:40 by lagea             #+#    #+#             */
/*   Updated: 2024/06/05 13:42:09 by lagea            ###   ########.fr       */
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

int col_init(t_col *col)
{
	col = malloc(sizeof(t_col));
	if (!col)
		return 0;
	col->dll = NULL;
	col->next = NULL;
	return 1;
}