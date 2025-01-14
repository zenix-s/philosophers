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
//                                INCLUDES                                     #
//-----------------------------------------------------------------------------#
# include <bits/pthreadtypes.h>
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
	t_philosopher	**philosophers;
	pthread_mutex_t	*forks;
}					t_deux;

//-----------------------------------------------------------------------------#
//                                PROTOTYPES                                   #
//-----------------------------------------------------------------------------#

void				print_error(char *message);
t_bool				valid_arguments(int argc, char **argv);

#endif
