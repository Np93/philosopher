#include "philo.h"

void	init_philo(t_para *para)
{
	int	n;

	n = para->n_philo;
	while (n >= 1)
	{
		para->philo[n].philo_id = n;
		para->philo[n].p_dead = 0;
		para->philo[n].p_meal = 0;
		para->philo[n].status = 't';
		para->philo[n].fork_left = n + 1;
		para->philo[n].fork_right = n;
		para->philo[n].para = para;
		if (n == para->n_philo)
		para->philo[n].fork_left = 1;
//		printf("%d\n", para->philo[n].philo_id);
//		printf("%d : %s\n", para->philo[n].fork_left, "gauche");
//		printf("%d : %s\n", para->philo[n].fork_right, "droite");
		n--;
	}
}

int	init_mutex(t_para *para)
{
	int	ret;
	int 	i;

	if (pthread_mutex_init(&para->lock, NULL) != 0)
		return (0);
	i = para->n_philo;
	while (i >= 1)
	{
		ret = pthread_mutex_init(&para->forks[i--], NULL);
		if (ret != 0)
			return (0);
	}
	return (1);
}

int	init(t_para *para, char **argv)
{
	para->n_philo = ft_atoi(argv[1]);
	para->die_t = ft_atoi(argv[2]);
	para->eat_t = ft_atoi(argv[3]);
	para->sleep_t = ft_atoi(argv[4]);
	if (argv[5])
		para->n_meal = ft_atoi(argv[5]);
	else
		para->n_meal = -1;
	if (!init_mutex(para))
	{
		printf("Error creating mutex\n");
		return (0);
	}
	init_philo(para);
	return (1);
}
