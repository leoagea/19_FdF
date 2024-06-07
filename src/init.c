/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:40 by lagea             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/07 14:20:16 by lagea            ###   ########.fr       */
=======
/*   Updated: 2024/06/07 12:55:03 by lagea            ###   ########.fr       */
>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

<<<<<<< HEAD
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
=======
>>>>>>> b0335ae3deecd1212a680d12c6a46292846214b9
