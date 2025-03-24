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

t_bool	is_philo_dead(const t_philosopher *philo)
{
	if (has_eaten_required_meals(philo))
		return (FALSE);
	return (timestamp() - philo->last_meal > philo->global->die_time);
}
