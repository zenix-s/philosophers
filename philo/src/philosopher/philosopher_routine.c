/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:11:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/19 21:24:48 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philosopher_clean_state(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->r_fork]);
}

void	*philosopher_routine(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	philo->routine = philosopher_eat_state;
	if (!is_even(philo->id))
		usleep(1500);
	print_log(philosopher, THINKING);
	philo->last_meal = timestamp();
	while (!philo->global->dead && !has_eaten_required_meals(philo))
		philo->routine(philo);
	return (NULL);
}
