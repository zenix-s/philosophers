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

void *philosopher_routine(void *philosopher)
{
	t_philosopher *philo;

	philo = (t_philosopher *)philosopher;
	philo->last_meal = timestamp();
	philo->routine = philosopher_eat_state;
	if (is_even(philo->id))
		usleep(1000);
	while (!philo->global->dead && !has_eaten_required_meals(philo))
		philo->routine(philo);

	return (NULL);
}

void philosopher_eat_state(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->global->forks[philosopher->left_fork]);
	print_log(philosopher, TAKE_FORK);
	pthread_mutex_lock(&philosopher->global->forks[philosopher->right_fork]);
	print_log(philosopher, TAKE_FORK);
	philosopher->last_meal = timestamp();
	print_log(philosopher, EATING);
	usleep(philosopher->global->time_to_eat * 1000);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->right_fork]);
	philosopher->meals++;
	philosopher->routine = philosopher_sleep_state;
}

void philosopher_sleep_state(t_philosopher *philosopher)
{
	uint64_t i;

	i = timestamp();
	print_log(philosopher, SLEEPING);
	while (!philosopher->global->dead)
	{
		if (timediff(i, timestamp()) >= philosopher->global->time_to_sleep)
			break ;
		usleep(1000);
	}
	philosopher->routine = philosopher_eat_state;
}
