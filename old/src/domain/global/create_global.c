/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_global.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:32:41 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/domain.h"

t_global	*create_global(t_global **global)
{
	*global = malloc(sizeof(t_global));
	if (*global == NULL)
	{
		return (print_error(ERROR_MALLOC, ERROR_MALLOC), NULL);
	}
	(*global)->dead = FALSE;
	(*global)->n_meals = 0;
	(*global)->time_to_die = 0;
	(*global)->time_to_eat = 0;
	(*global)->time_to_sleep = 0;
	(*global)->start_time = 0;
	return (*global);
}
