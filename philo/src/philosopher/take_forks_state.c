/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:33:42 by serferna          #+#    #+#             */
/*   Updated: 2025/02/19 21:30:31 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	take_forks_state(t_philosopher *philosopher)
{
	if (philosopher->global->dead)
	{
		philosopher->routine = philosopher_clean_state;
		return ;
	}
	if (philosopher->lock_l_fork == FALSE)
	{
		pthread_mutex_lock(&philosopher->global->forks[philosopher->l_fork]);
		philosopher->lock_l_fork = TRUE;
		print_log(philosopher, TAKE_FORK);
	}
	if (philosopher->global->dead)
	{
		philosopher->routine = philosopher_clean_state;
		return ;
	}
	if (philosopher->lock_r_fork == FALSE
		&& philosopher->l_fork != philosopher->r_fork)
	{
		pthread_mutex_lock(&philosopher->global->forks[philosopher->r_fork]);
		philosopher->lock_r_fork = TRUE;
		print_log(philosopher, TAKE_FORK);
	}
	philosopher->routine = philosopher_eat_state;
}
