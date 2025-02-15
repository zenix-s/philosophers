/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_machine_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:31:05 by serferna          #+#    #+#             */
/*   Updated: 2025/02/15 00:31:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void set_machine_error(t_state_machine *machine, char *error)
{
	machine->error = error;
	machine->execute = error_state;
}