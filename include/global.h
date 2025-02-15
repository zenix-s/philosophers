/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:58:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:04:01 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

//-----------------------------------------------------------------------------#
//                                INCLUDES
// ----------------------------------------------------------------------------#
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
// 									ENUMS
//-----------------------------------------------------------------------------#
typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

//-----------------------------------------------------------------------------#
// 								   PROTOTYPES
//-----------------------------------------------------------------------------#
t_bool		is_even(const int number);
uint64_t	timediff(uint64_t start, uint64_t end);
uint64_t	timestamp(void);
t_bool		to_uint64(const char *str, uint64_t *n);
t_bool		to_uint8(const char *str, uint8_t *n);

#endif
