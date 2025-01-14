/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:39:15 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 18:39:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static t_bool is_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

t_bool valid_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n", argv[0]);
		return (FALSE);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
