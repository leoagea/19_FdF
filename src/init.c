/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:40 by lagea             #+#    #+#             */
/*   Updated: 2024/06/07 17:42:34 by lagea            ###   ########.fr       */
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

t_dll	*dll_new(void)
{
	t_dll	*new;

	new = malloc(sizeof(t_dll));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	return (new);
}
