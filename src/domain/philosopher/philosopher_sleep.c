
#include "../../../include/domain.h"

static t_bool	is_philo_done_sleeping(t_philosopher *philo,
		uint64_t sleep_start)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(sleep_start, time) > philo->global->time_to_sleep)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_sleep(t_philosopher *philo)
{
	uint64_t	time;

	time = timestamp();
	print_log(philo, SLEEPING);
	while (!is_philo_done_sleeping(philo, time))
	{
		if (is_philo_dead(philo))
			return (FALSE);
		usleep(100);
	}
	return (TRUE);
}
