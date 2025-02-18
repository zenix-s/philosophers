/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:03:02 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:45:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philosophers.h"

void	error_state(t_state_machine *machine)
{
	printf("Error: %s\n", machine->error);
	machine->is_done = TRUE;
}
