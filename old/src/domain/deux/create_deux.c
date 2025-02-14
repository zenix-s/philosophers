/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deux.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:32:41 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/domain.h"

t_deux	*create_deux(const int argc, char **argv)
{
	t_deux	*deux;

	deux = malloc(sizeof(t_deux));
	if (deux == NULL)
		return (print_error(ERROR_MALLOC, ERROR_MALLOC), NULL);
	if (create_global(&deux->global) == NULL)
		return (free(deux), NULL);
	if (!to_uint64(argv[1], &deux->n_philosophers))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_PHIL), NULL);
	if (!to_uint64(argv[2], &deux->global->time_to_die))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_DIE_TIME), NULL);
	if (!to_uint64(argv[3], &deux->global->time_to_eat))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_EAT_TIME), NULL);
	if (!to_uint64(argv[4], &deux->global->time_to_sleep))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_SLEEP_TIME), NULL);
	if (argc == 6 && !to_uint64(argv[5], &deux->global->n_meals))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_MEALS), NULL);
	deux->global->dead = FALSE;
	return (deux);
}
