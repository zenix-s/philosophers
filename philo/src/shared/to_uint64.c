/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_uint64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:51:02 by serferna          #+#    #+#             */
/*   Updated: 2025/02/14 19:37:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/global.h"

t_bool	to_uint64(const char *str, uint64_t *n)
{
	*n = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (FALSE);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			*n = *n * 10 + (*str++ - '0');
		else
			return (FALSE);
	}
	return (TRUE);
}

t_bool	to_uint8(const char *str, uint8_t *n)
{
	uint64_t	tmp;

	if (!to_uint64(str, &tmp) || tmp > UINT8_MAX)
		return (FALSE);
	*n = (uint8_t)tmp;
	return (TRUE);
}
