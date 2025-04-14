/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:36:28 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:36:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

t_bool	is_philo_dead(t_philosopher *philo)
{
	uint64_t	last_meal_time;
	t_bool		is_dead;

	last_meal_time = philo->last_meal;
	is_dead = (timestamp() - last_meal_time > philo->global->die_time);
	return (is_dead);
}
