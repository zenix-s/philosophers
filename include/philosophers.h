/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:57:07 by serferna          #+#    #+#             */
/*   Updated: 2024/12/28 17:19:56 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread_create
# include <pthread.h>
// Malloc
# include <stdlib.h>

typedef struct s_philosopher
{
	int			id;
	int			contributions;
	pthread_t	thread;
}				t_philosopher;

typedef enum s_bool
{
	FALSE,
	TRUE
}				t_bool;

#endif
