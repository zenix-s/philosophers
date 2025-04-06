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

void	philosopher_eat_state(t_philosopher *philosopher)
{
	if (philosopher->global->dead)
		return ;
	pthread_mutex_lock(&philosopher->global->forks[philosopher->l_fork]);
	print_log(philosopher, TAKE_FORK);
	if (philosopher->global->dead)
		return ;
	pthread_mutex_lock(&philosopher->global->forks[philosopher->r_fork]);
	print_log(philosopher, TAKE_FORK);
	if (philosopher->global->dead)
		return ;
	print_log(philosopher, EATING);
	philosopher->last_meal = timestamp();
	while (!philosopher->global->dead)
	{
		if (timediff(philosopher->last_meal,
				timestamp()) >= philosopher->global->eat_time
			|| philosopher->global->dead)
			break ;
		usleep(50);
	}
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->l_fork]);
	pthread_mutex_unlock(&philosopher->global->forks[philosopher->r_fork]);
	philosopher->meals++;
	philosopher->routine = philosopher_sleep_state;
}
