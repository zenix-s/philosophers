/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:35:31 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 13:35:31 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/domain.h"

void	*philosopher_life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->last_meal = timestamp();
	if (is_even(philo->id))
		usleep(1000);
	while (philo->meals < philo->global->n_meals && !is_philo_dead(philo))
	{
		if (!philo_eat(philo) || has_eaten_required_meals(philo)
			|| is_philo_dead(philo))
			break ;
		philo_sleep(philo);
		if (is_philo_dead(philo))
			break ;
		print_log(philo, THINKING);
	}
	return (NULL);
}
