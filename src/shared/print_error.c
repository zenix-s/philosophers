/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:35:31 by serferna          #+#    #+#             */
/*   Updated: 2025/01/14 13:35:31 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"
#include <unistd.h>

static uint64_t	ft_strlen(char *str)
{
	uint64_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(char *error_code, char *error_message)
{
	write(2, "ERROR\n", 6);
	write(2, error_code, ft_strlen(error_code));
	write(2, error_message, ft_strlen(error_message));
}
