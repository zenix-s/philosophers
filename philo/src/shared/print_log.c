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

#include "../../include/domain.h"

static uint64_t	timelog(const t_philosopher *philo)
{
	return (timestamp() - philo->global->start_time);
}

void	print_log(const t_philosopher *philo, const t_action action)
{
	int64_t	philo_id;

	philo_id = philo->id + 1;
	pthread_mutex_lock(&philo->global->write_mutex);
	if (philo->global->dead == FALSE)
	{
		if (action == TAKE_FORK)
			printf("%lu %lu has taken a fork\n", timelog(philo), philo_id);
		else if (action == EATING)
			printf("%lu %lu is eating\n", timelog(philo), philo_id);
		else if (action == SLEEPING)
			printf("%lu %lu is sleeping\n", timelog(philo), philo_id);
		else if (action == THINKING)
			printf("%lu %lu is thinking\n", timelog(philo), philo_id);
		else if (action == DIED)
			printf("%lu %lu died\n", timelog(philo), philo_id);
	}
	pthread_mutex_unlock(&philo->global->write_mutex);
}
