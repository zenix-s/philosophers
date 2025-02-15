/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:33:46 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 15:33:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philosopher_eat_state(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->global->forks[philosopher->l_fork]);
	if (philosopher->global->dead)
		return ;
	print_log(philosopher, TAKE_FORK);
	pthread_mutex_lock(&philosopher->global->forks[philosopher->r_fork]);
	if (philosopher->global->dead)
	{
		pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
		return ;
	}
	print_log(philosopher, TAKE_FORK);
	philosopher->last_meal = timestamp();
	print_log(philosopher, EATING);
	while (!philosopher->global->dead)
	{
		if (timediff(philosopher->last_meal,
				timestamp()) >= philosopher->global->eat_time)
			break ;
		usleep(50);
	}
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->r_fork]);
	philosopher->meals++;
	philosopher->routine = philosopher_sleep_state;
}
