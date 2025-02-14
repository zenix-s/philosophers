/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:03:54 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 23:03:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "domain.h"
# include "global.h"
# include "state_machine.h"

void	error_state(t_state_machine *machine);
void	validate_arguments_state(t_state_machine *machine);
void	create_global_state(t_state_machine *machine);

#endif
