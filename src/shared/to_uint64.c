
#include "../../include/philosophers.h"

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
