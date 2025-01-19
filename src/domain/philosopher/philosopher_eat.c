
#include "../../../include/domain.h"

static t_bool	is_philo_done_eating(t_philosopher *philo)
{
	uint64_t	time;

	time = timestamp();
	if (timediff(philo->last_meal, time) > philo->global->time_to_eat)
		return (TRUE);
	return (FALSE);
}

t_bool	philo_eat(t_philosopher *philo)
{
	philo->last_meal = timestamp();
	print_log(philo, EATING);
	// Pre
	if (has_eaten_required_meals(philo))
		return (TRUE);
	philo->meals++;
	while (!is_philo_done_eating(philo))
	{
		if (is_philo_dead(philo))
			return (FALSE);
		usleep(100);
	}
	return (TRUE);
}
