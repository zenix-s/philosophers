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

#include "../include/domain.h"
#include "../include/philosophers.h"

t_bool	birth_philosophers(t_deux *deux)
{
	uint64_t	i;

	deux->philosophers = malloc(sizeof(t_philosopher *) * deux->n_philosophers);
	i = -1;
	while (++i < deux->n_philosophers)
	{
		if (create_philosopher(&(deux->philosophers)[i], i, deux->global))
			continue ;
		while (i-- > 0)
			free(deux->philosophers[i]);
		free(deux->philosophers);
		return (FALSE);
	}
	deux->global->start_time = timestamp();
	i = -1;
	while (++i < deux->n_philosophers)
	{
		deux->philosophers[i]->left_fork_mutex = &deux->forks[i];
		deux->philosophers[i]->right_fork_mutex = &deux->forks[(i + 1)
			% deux->n_philosophers];
		pthread_create(&deux->philosophers[i]->thread, NULL, philosopher_life,
			deux->philosophers[i]);
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

int	main(int argc, char **argv)
{
	uint64_t	i;
	t_deux		*deux;
	t_bool		all_eaten;
	t_bool		any_dead;

	if (!valid_arguments(argc, argv))
		return (EXIT_FAILURE);
	deux = create_deux(argc, argv);
	if (deux == NULL)
		return (print_error(ERROR_MALLOC, ERROR_MALLOC), EXIT_FAILURE);
	if (birth_philosophers(deux) == FALSE)
		return (EXIT_FAILURE);
	all_eaten = FALSE;
	any_dead = FALSE;
	while (!all_eaten && !any_dead)
	{
		i = -1;
		all_eaten = TRUE;
		while (++i < deux->n_philosophers)
		{
			if (has_eaten_required_meals(deux->philosophers[i]))
				continue ;
			all_eaten = FALSE;
			if (!is_philo_dead(deux->philosophers[i]))
				continue ;
			any_dead = TRUE;
			print_log(deux->philosophers[i], DIED);
			join_threads(deux);
			return (EXIT_FAILURE);
		}
		usleep(100);
	}
	join_threads(deux);
	i = 0;
	while (i < deux->n_philosophers)
	{
		printf("Philosopher %d finished with %lu iterations\n",
			deux->philosophers[i]->id, deux->philosophers[i]->meals);
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
	return (EXIT_SUCCESS);
}
