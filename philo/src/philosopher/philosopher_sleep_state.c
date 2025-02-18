/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleep_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:32:32 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 15:32:44 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philosopher_sleep_state(t_philosopher *philosopher)
{
	uint64_t	start;

	start = timestamp();
	print_log(philosopher, SLEEPING);
	while (!philosopher->global->dead)
	{
		if (timediff(start, timestamp()) >= philosopher->global->sleep_time)
			break ;
		usleep(50);
	}
	philosopher->routine = philosopher_eat_state;
	print_log(philosopher, THINKING);
}
