/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:33:46 by serferna          #+#    #+#             */
/*   Updated: 2025/02/19 21:38:03 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static void	await_painful_dead(t_philosopher *philosopher)
{
	while (!philosopher->global->dead)
	{
		usleep(200);
	}
}

static t_bool	take_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->global->forks[philosopher->l_fork]);
	print_log(philosopher, TAKE_FORK);
	if (philosopher->global->dead)
	{
		pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
		return (FALSE);
	}
	if (philosopher->global->n_philos == 1)
	{
		await_painful_dead(philosopher);
		pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
		return (FALSE);
	}
	pthread_mutex_lock(&philosopher->global->forks[philosopher->r_fork]);
	print_log(philosopher, TAKE_FORK);
	if (philosopher->global->dead)
	{
		pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
		pthread_mutex_unlock(&philosopher->global->forks[philosopher->r_fork]);
		return (FALSE);
	}
	return (TRUE);
}

void	philosopher_eat_state(t_philosopher *philosopher)
{
	uint64_t	start_eating_time;

	if (philosopher->global->dead)
		return ;
	if (!take_forks(philosopher))
		return ;
	print_log(philosopher, EATING);
	philosopher->last_meal = timestamp();
	start_eating_time = philosopher->last_meal;
	while (!philosopher->global->dead)
	{
		if (timediff(start_eating_time,
				timestamp()) >= philosopher->global->eat_time
			|| philosopher->global->dead)
			break ;
		usleep(200);
	}
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->r_fork]);
	philosopher->meals++;
	philosopher->routine = philosopher_sleep_state;
}
