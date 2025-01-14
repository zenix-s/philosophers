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
#include <stdint.h>

static t_bool	is_number(const char *str)
{
	uint64_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			print_error(ERROR_ARGUMENTS, ERROR_NOT_NUMBER);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	valid_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		print_error(ERROR_ARGUMENTS, ERROR_USAGE);
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
