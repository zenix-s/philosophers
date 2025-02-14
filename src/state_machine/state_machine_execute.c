/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine_execute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:17:37 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 22:18:24 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/state_machine.h"

void state_machine_execute(t_state_machine *machine)
{
	if (machine->execute)
		machine->execute(machine);
}
