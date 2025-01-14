/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:32:41 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

//-----------------------------------------------------------------------------#
//                                CONSTANTS                                    #
// ----------------------------------------------------------------------------#

# define ERROR_ARGUMENTS "Invalid arguments\n"
# define ERROR_MALLOC "Error allocating memory\n"

# define ERROR_USAGE \
	"Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n"
# define ERROR_NOT_NUMBER "Argument is not a number\n"
# define ERROR_N_PHIL "Invalid parameter number_of_philosophers"
# define ERROR_DIE_TIME "Invalid parameter time_to_die"
# define ERROR_EAT_TIME "Invalid parameter time_to_eat"
# define ERROR_SLEEP_TIME "Invalid parameter time_to_sleep"
# define ERROR_N_MEALS "Invalid parameter number_of_times_each_philosopher_must_eat"

//-----------------------------------------------------------------------------#
//                                INCLUDES                                     #
//-----------------------------------------------------------------------------#
# include <stdio.h>
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread_create
# include <pthread.h>
// Malloc
# include <stdlib.h>
// uint64_t
# include <stdint.h>

//-----------------------------------------------------------------------------#
//                                STRUCTS                                      #
//-----------------------------------------------------------------------------#
typedef struct s_philosopher
{
	int				id;
	int				contributions;
	pthread_t		thread;
}					t_philosopher;

typedef enum s_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_deux
{
	uint64_t		n_philosophers;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		n_meals;
	t_philosopher	**philosophers;
	pthread_mutex_t	*forks;
}					t_deux;

//-----------------------------------------------------------------------------#
//                                PROTOTYPES                                   #
//-----------------------------------------------------------------------------#

t_bool				to_uint64(const char *str, uint64_t *n);
void				print_error(char *error_code, char *error_message);

t_bool				valid_arguments(int argc, char **argv);

#endif
