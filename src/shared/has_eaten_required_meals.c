/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_eaten_required_meals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:37:37 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 12:37:37 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

t_bool has_eaten_required_meals(t_philosopher *philo)
{
	return (philo->meals >= philo->global->n_meals);
}