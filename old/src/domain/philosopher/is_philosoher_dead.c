
#include "../../../include/domain.h"

t_bool	is_philo_dead(t_philosopher *philo)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(philo->last_meal, time) > philo->global->time_to_die)
		return (TRUE);
	return (FALSE);
}
