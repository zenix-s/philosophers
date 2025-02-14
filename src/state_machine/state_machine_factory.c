/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_state_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:13:08 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 22:46:04 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/state_machine.h"
#include <stdio.h>

t_state_machine	*create_state_machine(int argc, char **argv)
{
	t_state_machine	*state_machine;

	state_machine = (t_state_machine *)malloc(sizeof(t_state_machine));
	if (!state_machine)
		return (NULL);
	// Initialize state machine
	state_machine->execute = NULL;
	state_machine->is_done = FALSE;

	// Initialize context
	state_machine->argc = argc;
	state_machine->argv = argv;

	return (state_machine);
}
