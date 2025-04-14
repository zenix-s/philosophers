/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:03:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:03:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "domain.h"
# include "global.h"

void	error_state(t_state_machine *machine);
void	validate_arguments_state(t_state_machine *machine);
void	create_global_state(t_state_machine *machine);
void	create_forks_state(t_state_machine *machine);
void	create_philosophers_state(t_state_machine *machine);
void	start_simulation_state(t_state_machine *machine);
void	join_threads_state(t_state_machine *machine);
void	monitor_simulation_state(t_state_machine *machine);
void	destroy_simulation_state(t_state_machine *machine);

void	*philosopher_routine(void *philosopher);
void	philosopher_eat_state(t_philosopher *philosopher);
void	philosopher_sleep_state(t_philosopher *philosopher);
void	take_forks_state(t_philosopher *philosopher);
void	philosopher_clean_state(t_philosopher *philosopher);

t_bool	is_philo_dead(t_philosopher *philo);
t_bool	has_eaten_required_meals(const t_philosopher *philo);

#endif
