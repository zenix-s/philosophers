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

#include "../include/philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t		g_max_meals = 10;
uint64_t		g_count = 0;
pthread_mutex_t	g_count_mutex;

t_bool	is_par(const int n)
{
	return (n % 2 == 0);
}

uint64_t	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

uint64_t	timediff(uint64_t start, uint64_t end)
{
	return (end - start);
}

t_bool	is_philo_dead(t_philosopher *philo)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(philo->last_meal, time) > philo->times->time_to_die)
		return (TRUE);
	return (FALSE);
}

t_bool	is_philo_done_eating(t_philosopher *philosopher)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(philosopher->last_meal,
			time) > philosopher->times->time_to_eat)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_eat(t_philosopher *philosopher)
{
	philosopher->last_meal = timestamp();
	printf("%lu %d is eating\n", timestamp(), philosopher->id);
	// Pre
	pthread_mutex_lock(&g_count_mutex);
	if (g_count >= g_max_meals)
	{
		pthread_mutex_unlock(&g_count_mutex);
		return (FALSE);
	}
	g_count++;
	philosopher->contributions++;
	pthread_mutex_unlock(&g_count_mutex);
	// End pre
	while (!is_philo_done_eating(philosopher))
	{
		usleep(1000);
	}
	return (TRUE);
}

t_bool	is_philo_done_sleeping(t_philosopher *philosopher, uint64_t sleep_start)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(sleep_start, time) > philosopher->times->time_to_sleep)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_sleep(t_philosopher *philosopher)
{
	uint64_t	time;

	time = timestamp();
	printf("%lu %d is sleeping\n", timestamp(), philosopher->id);
	while (!is_philo_done_sleeping(philosopher, time))
	{
		if (is_philo_dead(philosopher))
			return (FALSE);
		usleep(100);
	}
	return (TRUE);
}

void	*philosopher_life(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	philosopher->last_meal = timestamp();
	if (is_par(philosopher->id))
	{
		usleep(1000);
	}
	while (g_count < g_max_meals && !is_philo_dead(philosopher))
	{
		if (philo_eat(philosopher) == FALSE)
		{
			break ;
		}
		if (is_philo_dead(philosopher))
			break ;
		philo_sleep(philosopher);
		if (is_philo_dead(philosopher))
			break ;
		printf("%lu %d is thinking\n", timestamp(), philosopher->id);
	}
	return (NULL);
}

t_bool	create_philosopher(t_philosopher **philosopher, const int id,
		t_times *times)
{
	*philosopher = malloc(sizeof(t_philosopher));
	if (*philosopher == NULL)
	{
		return (FALSE);
	}
	(*philosopher)->id = id;
	(*philosopher)->contributions = 0;
	(*philosopher)->last_meal = timestamp();
	(*philosopher)->times = times;
	pthread_create(&(*philosopher)->thread, NULL, philosopher_life,
		*philosopher);
	return (TRUE);
}

t_bool	birth_philosophers(t_deux *deux)
{
	uint64_t	i;

	deux->philosophers = malloc(sizeof(t_philosopher *) * deux->n_philosophers);
	i = 0;
	while (i < deux->n_philosophers)
	{
		if (create_philosopher(&(deux->philosophers)[i], i, deux->times))
		{
			i++;
			continue ;
		}
		while (i > 0)
		{
			i--;
			free((deux->philosophers)[i]);
		}
		free(deux->philosophers);
		return (FALSE);
	}
	return (TRUE);
}

void	join_threads(t_deux *deux)
{
	uint64_t	i;

	i = 0;
	while (i < deux->n_philosophers)
	{
		pthread_join(deux->philosophers[i]->thread, NULL);
		i++;
	}
}

t_deux	*create_deux(const int argc, char **argv)
{
	t_deux	*deux;

	deux = malloc(sizeof(t_deux));
	if (deux == NULL)
		return (print_error(ERROR_MALLOC, ERROR_MALLOC), NULL);
	deux->times = malloc(sizeof(t_times));
	if (deux->times == NULL)
		return (free(deux), print_error(ERROR_MALLOC, ERROR_MALLOC), NULL);
	if (!to_uint64(argv[1], &deux->n_philosophers))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_PHIL), NULL);
	if (!to_uint64(argv[2], &deux->times->time_to_die))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_DIE_TIME), NULL);
	if (!to_uint64(argv[3], &deux->times->time_to_eat))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_EAT_TIME), NULL);
	if (!to_uint64(argv[4], &deux->times->time_to_sleep))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_SLEEP_TIME), NULL);
	if (argc == 6 && !to_uint64(argv[5], &deux->n_meals))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_MEALS), NULL);
	return (deux);
}

int	main(int argc, char **argv)
{
	uint64_t	i;
	t_deux		*deux;

	if (!valid_arguments(argc, argv))
	{
		return (EXIT_FAILURE);
	}
	deux = create_deux(argc, argv);
	if (deux == NULL)
	{
		print_error(ERROR_MALLOC, ERROR_MALLOC);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&g_count_mutex);
	if (birth_philosophers(deux) == FALSE)
	{
		return (EXIT_FAILURE);
	}
	while (g_count != g_max_meals)
	{
		i = 0;
		while (i < deux->n_philosophers)
		{
			if (is_philo_dead(deux->philosophers[i]))
			{
				join_threads(deux);
				return (EXIT_FAILURE);
			}
			i++;
		}
		usleep(100);
	}
	join_threads(deux);
	i = 0;
	while (i < deux->n_philosophers)
	{
		printf("Philosopher %d finished with %d iterations\n",
			deux->philosophers[i]->id, deux->philosophers[i]->contributions);
		i++;
	}
	i = 0;
	while (i < deux->n_philosophers)
	{
		free(deux->philosophers[i]);
		i++;
	}
	free(deux->philosophers);
	free(deux);
	pthread_mutex_destroy(&g_count_mutex);
	return (EXIT_SUCCESS);
}
