#include "philo.h"

void	print_eat(t_philo *philo)
{
	t_para	*para;

	para = philo->para;
	if (!para->stop)
	{
		pthread_mutex_lock(&para->forks[philo->fork_left]);
		print_action(philo, " has taken a fork");
		pthread_mutex_lock(&para->forks[philo->fork_right]);
		print_action(philo, " has taken a fork");
		print_action(philo, " is eating");
		philo->p_meal++;
		minisleep(para->eat_t, philo);
		philo->last_meal = timer();
		pthread_mutex_unlock(&para->forks[philo->fork_left]);
		pthread_mutex_unlock(&para->forks[philo->fork_right]);
	}
}

int	print_action(t_philo *philo, char *action)
{
	long	t_dif;
	t_para	*para;

	para = philo->para;
//	pthread_mutex_lock(&para->lock);
	if (!para->stop)
	{
		t_dif = timer() - para->time_start;
		pthread_mutex_lock(&para->lock);
		if (para->stop)
		{
			pthread_mutex_unlock(&para->lock);
			return (0);
		}
		printf("%ld : ", t_dif);
		printf("%d", philo->philo_id);
		printf("%s\n", action);
		if (ft_strstr(action, "died") != 0)
		{
			para->stop = 1;
			usleep(100);
		}
		pthread_mutex_unlock(&para->lock);
	}
	return (0);
}

void	minisleep(long action, t_philo *philo)
{
	long	start;

	start = timer();
	while (1)
	{
		if (check_dead(philo))
			break ;
		if ((timer() - start) >= action)
			break ;
		usleep(50);
	}
}
