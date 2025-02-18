/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:52:52 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:06:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(const int argc, char **argv)
{
	t_state_machine	*machine;
	int				exit_code;

	exit_code = EXIT_SUCCESS;
	machine = create_state_machine(argc, argv);
	if (machine == NULL)
		return (EXIT_FAILURE);
	machine->execute = validate_arguments_state;
	while (!machine->is_done)
		machine->execute(machine);
	if (machine->error != NULL)
		exit_code = EXIT_FAILURE;
	free(machine);
	return (exit_code);
}
