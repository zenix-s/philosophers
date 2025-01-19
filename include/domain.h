/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domain.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:32:41 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMAIN_H

# define DOMAIN_H

# include "philosophers.h"

//-----------------------------------------------------------------------------#
//                                CONSTANTS                                    #
// ----------------------------------------------------------------------------#

# define ERROR_ARGUMENTS "Invalid arguments\n"
# define ERROR_MALLOC "Error allocating memory\n"

# define ERROR_USAGE \
	"Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n"
# define ERROR_NOT_NUMBER "Argument is not a number\n"
# define ERROR_N_PHIL "Invalid number_of_philosophers"
# define ERROR_DIE_TIME "Invalid time_to_die"
# define ERROR_EAT_TIME "Invalid time_to_eat"
# define ERROR_SLEEP_TIME "Invalid time_to_sleep"
# define ERROR_N_MEALS "Invalid number_of_times_each_philosopher_must_eat"

//-----------------------------------------------------------------------------#
// 									ENUMS                                      #
//-----------------------------------------------------------------------------#

typedef enum s_action
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}					t_action;

//-----------------------------------------------------------------------------#
//                                STRUCTS                                      #
//-----------------------------------------------------------------------------#

typedef struct s_global
{
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		n_meals;
	uint64_t		start_time;
	t_bool			dead;
	pthread_mutex_t	write_mutex;
}					t_global;

typedef struct s_philosopher
{
	int				id;
	uint64_t		meals;
	uint64_t		last_meal;
	pthread_t		thread;
	t_bool			left_fork;
	pthread_mutex_t	*left_fork_mutex;
	t_bool			right_fork;
	pthread_mutex_t	*right_fork_mutex;
	t_global		*global;
}					t_philosopher;

typedef struct s_deux
{
	uint64_t		n_philosophers;
	t_global		*global;
	t_philosopher	**philosophers;
	pthread_mutex_t	*forks;
}					t_deux;

//-----------------------------------------------------------------------------#
//                                PROTOTYPES                                   #
//-----------------------------------------------------------------------------#

// global
t_global			*create_global(t_global **global);

// deux
t_deux				*create_deux(const int argc, char **argv);

// philosopher
t_bool				philo_eat(t_philosopher *philo);
void				print_log(t_philosopher *philo, t_action action);
t_bool				is_philo_dead(t_philosopher *philo);
t_bool				has_eaten_required_meals(t_philosopher *philo);
t_bool				create_philosopher(t_philosopher **philo, const int id,
						t_global *times);
void				*philosopher_life(void *arg);
t_bool				philo_sleep(t_philosopher *philo);

#endif
