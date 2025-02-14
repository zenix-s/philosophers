
#include "../../../include/domain.h"

t_bool	create_philosopher(t_philosopher **philo, const int id, t_global *times)
{
	*philo = malloc(sizeof(t_philosopher));
	if (*philo == NULL)
	{
		return (FALSE);
	}
	(*philo)->id = id;
	(*philo)->meals = 0;
	(*philo)->last_meal = timestamp();
	(*philo)->global = times;
	(*philo)->left_fork = FALSE;
	(*philo)->right_fork = FALSE;
	return (TRUE);
}
