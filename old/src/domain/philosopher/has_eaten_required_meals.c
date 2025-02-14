
#include "../../../include/domain.h"

t_bool has_eaten_required_meals(t_philosopher *philo)
{
	if (philo->meals >= philo->global->n_meals && philo->global->n_meals != 0)
		return (TRUE);
	return (FALSE);
}
