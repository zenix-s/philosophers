/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:13:15 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 22:35:11 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_MACHINE_H
# define STATE_MACHINE_H

# include "global.h"
# include "domain.h"

// the function pointer that recives the machine

typedef struct s_state_machine
{
	// State machine
	char		*error;
	t_bool		is_done;
	void		(*execute)(struct s_state_machine *);

	// Context
	int			argc;
	char		**argv;
	t_global 	*global;
}				t_state_machine;

t_state_machine	*create_state_machine(int argc, char **argv);
void			state_machine_execute(t_state_machine *machine);
void			set_machine_error(t_state_machine *machine, char *error);

#endif
