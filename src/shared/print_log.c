/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:21:33 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:21:38 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static uint64_t	timelog(t_philosopher *philo)
{
	return (timestamp() - philo->global->start_time);
}

void	print_log(t_philosopher *philo, t_action action)
{
	pthread_mutex_lock(&philo->global->write_mutex);
	if (philo->global->dead == FALSE)
	{
		if (action == TAKE_FORK)
			printf("%lu %d has taken a fork\n", timelog(philo), philo->id);
		else if (action == EATING)
			printf("%lu %d is eating\n", timelog(philo), philo->id);
		else if (action == SLEEPING)
			printf("%lu %d is sleeping\n", timelog(philo), philo->id);
		else if (action == THINKING)
			printf("%lu %d is thinking\n", timelog(philo), philo->id);
		else if (action == DIED)
			printf("%lu %d died\n", timelog(philo), philo->id);
	}
	pthread_mutex_unlock(&philo->global->write_mutex);
}
