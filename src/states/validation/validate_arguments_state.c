/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:01:38 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:02:48 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philosophers.h"

static t_bool	is_number(const char *str)
{
	uint64_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	validate_arguments_state(t_state_machine *machine)
{
	int	i;

	if (machine->argc < 5 || machine->argc > 6)
	{
		machine->error = ERROR_USAGE;
		machine->execute = error_state;
		return;
	}
	i = 1;
	while (i < machine->argc)
	{
		printf("Argv[%d]: %s\n", i, machine->argv[i]);
		if (!is_number(machine->argv[i]))
		{
			machine->error = ERROR_NOT_NUMBER;
			machine->execute = error_state;
			return;
		}
		i++;
	}
	machine->execute = create_global_state;
}
