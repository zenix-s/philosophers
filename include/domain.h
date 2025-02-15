/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domain.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:32:41 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 22:29:18 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMAIN_H
# define DOMAIN_H

# include "global.h"

//-----------------------------------------------------------------------------#
//                                ERRORS
// ----------------------------------------------------------------------------#
# define ERROR_MALLOC "Error allocating memory\n"

# define ERROR_USAGE \
	"Invalid arguments\n" \
	"Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat>" \
	"<time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n"

# define ERROR_NOT_NUMBER \
	"Invalid arguments\n" \
	"Argument is not a number\n"

# define ERROR_N_PHIL \
	"Invalid arguments\n" \
	"Invalid number_of_philosophers"

# define ERROR_DIE_TIME \
	"Invalid arguments\n" \
	"Invalid time_to_die"

# define ERROR_EAT_TIME \
	"Invalid arguments\n" \
	"Invalid time_to_eat"
# define ERROR_SLEEP_TIME \
	"Invalid arguments\n" \
	"Invalid time_to_sleep"

# define ERROR_N_MEALS \
	"Invalid arguments\n" \
	"Invalid number_of_times_each_philosopher_must_eat"

//-----------------------------------------------------------------------------#
// 									ENUMS
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
//                                STRUCTS
//-----------------------------------------------------------------------------#

typedef struct s_philosopher
{
	int				id;
	uint64_t		meals;
	uint64_t		last_meal;
	pthread_t		thread;
	uint64_t 		left_fork;
	uint64_t 		right_fork;
	struct s_global	*global;
	void 			(*routine)(struct s_philosopher *);
}					t_philosopher;

typedef struct s_global
{
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		n_meals;
	uint64_t		start_time;
	t_bool			dead;
	pthread_mutex_t	write_mutex;
	uint8_t 		n_philos;
	pthread_mutex_t	*forks;
	t_philosopher	**philosophers;
}					t_global;

typedef struct s_state_machine
{
	// State machine
	char		*error;
	t_bool		is_done;
	void		(*execute)(struct s_state_machine *);

	// Context
	int				argc;
	char			**argv;
	t_global		*global;
}				t_state_machine;


//-----------------------------------------------------------------------------#
// 							      PROTOTYPES
//-----------------------------------------------------------------------------#

t_state_machine	*create_state_machine(int argc, char **argv);
void			set_machine_error(t_state_machine *machine, char *error);


void			print_log(t_philosopher *philo, t_action action);

#endif
