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
// 									ENUMS                                      #
//-----------------------------------------------------------------------------#

typedef enum s_bool
{
	FALSE,
	TRUE
}			t_bool;

//-----------------------------------------------------------------------------#
//                                PROTOTYPES                                   #
//-----------------------------------------------------------------------------#

t_bool		to_uint64(const char *str, uint64_t *n);
void		print_error(char *error_code, char *error_message);
uint64_t	timestamp(void);
t_bool		valid_arguments(int argc, char **argv);
uint64_t	timediff(uint64_t start, uint64_t end);
t_bool		is_even(const int n);

#endif
