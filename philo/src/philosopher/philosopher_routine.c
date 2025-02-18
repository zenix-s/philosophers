/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:11:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:11:54 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*philosopher_routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	philo->last_meal = timestamp();
	philo->routine = philosopher_eat_state;
	if (is_even(philo->id))
		usleep(15000);
	while (!philo->global->dead && !has_eaten_required_meals(philo))
		philo->routine(philo);
	return (NULL);
}
