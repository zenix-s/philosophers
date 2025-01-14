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
#include <stdio.h>
#include <stdlib.h>

int				g_count = 0;
pthread_mutex_t	g_count_mutex;

uint64_t	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	*philosopher_life(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	printf("Time: %lu\n", timestamp());
	printf("Philosopher %d is alive\n", philosopher->id);
	while (g_count < 10)
	{
		pthread_mutex_lock(&g_count_mutex);
		if (g_count >= 10)
		{
			pthread_mutex_unlock(&g_count_mutex);
			break ;
		}
		g_count++;
		philosopher->contributions++;
		pthread_mutex_unlock(&g_count_mutex);
		usleep(1000);
	}
	return (NULL);
}

t_bool	create_philosopher(t_philosopher **philosopher, const int id)
{
	*philosopher = malloc(sizeof(t_philosopher));
	if (*philosopher == NULL)
	{
		return (FALSE);
	}
	(*philosopher)->id = id;
	(*philosopher)->contributions = 0;
	pthread_create(&(*philosopher)->thread, NULL, philosopher_life,
		*philosopher);
	return (TRUE);
}

t_bool	birth_philosophers(int n_philosophers, t_philosopher ***philosophers)
{
	int	i;

	*philosophers = malloc(sizeof(t_philosopher *) * n_philosophers);
	i = 0;
	while (i < n_philosophers)
	{
		if (create_philosopher(&(*philosophers)[i], i))
		{
			i++;
			continue ;
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

void	join_threads(const int n_philosophers, t_philosopher **philosophers)
{
	int	i;

	i = 0;
	while (i < n_philosophers)
	{
		pthread_join(philosophers[i]->thread, NULL);
		i++;
	}
}


t_deux	*create_deux(const int argc, char **argv)
{
	t_deux	*deux;

	deux = malloc(sizeof(t_deux));
	if (deux == NULL)
		return (print_error(ERROR_MALLOC, ERROR_MALLOC), NULL);
	if (!to_uint64(argv[1], &deux->n_philosophers))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_PHIL), NULL);
	if (!to_uint64(argv[2], &deux->time_to_die))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_DIE_TIME), NULL);
	if (!to_uint64(argv[3], &deux->time_to_eat))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_EAT_TIME), NULL);
	if (!to_uint64(argv[4], &deux->time_to_sleep))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_SLEEP_TIME), NULL);
	if (argc == 6 && !to_uint64(argv[5], &deux->n_meals))
		return (free(deux), print_error(ERROR_MALLOC, ERROR_N_MEALS), NULL);
	return (deux);
}

int	main(int argc, char **argv)
{
	uint64_t		i;
	t_deux			*deux;

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

	if (birth_philosophers(deux->n_philosophers, &(deux->philosophers)) == FALSE)
	{
		return (EXIT_FAILURE);
	}
	while (g_count != 10)
	{
		usleep(1000);
	}
	join_threads(deux->n_philosophers, deux->philosophers);
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
