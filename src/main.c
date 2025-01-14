
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:18:58 by serferna          #+#    #+#             */
/*   Updated: 2024/12/30 16:05:26 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock


#include <stdio.h>
#include <unistd.h>
// gettimeofday
#include <sys/time.h>
// pthread_create
#include <pthread.h>
// Malloc
#include <stdlib.h>

int g_count = 0;
pthread_mutex_t g_count_mutex;


typedef struct s_philosopher
{
    int id;
	int contributions;
	pthread_t thread;
} t_philosopher;

typedef enum s_bool
{
    FALSE,
    TRUE
} t_bool;


void *philosopher_life(void *arg)
{
    t_philosopher *philosopher = (t_philosopher *)arg;

    printf("Philosopher %d is alive\n", philosopher->id);

	while (g_count < 100)
	{
		pthread_mutex_lock(&g_count_mutex);
		if (g_count >= 100)
        {
            pthread_mutex_unlock(&g_count_mutex);
            break ;
        }
		g_count++;
		philosopher->contributions++;
		pthread_mutex_unlock(&g_count_mutex);
		usleep(100);
	}

    return (NULL);
}

t_bool create_philosopher(t_philosopher **philosopher, const int id)
{
	*philosopher = malloc(sizeof(t_philosopher));
    if (*philosopher == NULL)
    {
        return (FALSE);
    }
    (*philosopher)->id = id;
    (*philosopher)->contributions = 0;
	pthread_create(&(*philosopher)->thread, NULL, philosopher_life, *philosopher);
	return (TRUE);
}

t_bool birth_philosophers(int n_philosophers, t_philosopher ***philosophers)
{
	int i;

	*philosophers = malloc(sizeof(t_philosopher *) * n_philosophers);
	i = 0;
	while (i < n_philosophers)
	{
		if (create_philosopher(&(*philosophers)[i], i))
		{
			i++;
			continue;
		}
		while (i > 0)
		{
			i--;
			free((*philosophers)[i]);
		}
		free(*philosophers);
		return (FALSE);
	}
	return (TRUE);
}

void join_threads(int n_philosophers, t_philosopher **philosophers)
{
	int i;
	i = 0;
	while (i < n_philosophers)
	{
		pthread_join(philosophers[i]->thread, NULL);
		i++;
	}
}

int	main(void)
{
	int n_philosophers = 3;
	int i;
	t_philosopher **philosophers;

	if (birth_philosophers(n_philosophers, &philosophers) == FALSE)
	{
		return (EXIT_FAILURE);
	}

	join_threads(n_philosophers, philosophers);

	i = 0;
	while (i < n_philosophers)
    {
        printf("Philosopher %d finished with %d iterations\n", philosophers[i]->id, philosophers[i]->contributions);
        i++;
    }

	i = 0;
	while (i < n_philosophers)
    {
        free(philosophers[i]);
        i++;
    }
	free(philosophers);

	pthread_mutex_destroy(&g_count_mutex);

	return (EXIT_SUCCESS);
}
