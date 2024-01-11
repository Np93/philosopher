/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:27:57 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/25 17:27:59 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	check_dead(t_philo *philo)
{
	t_para	*para;

	para = philo->para;
	if (para->die_t - 1 < (timer() - philo->last_meal))
	{
		if (!para->stop)
			print_action(philo, " died");
		return (1);
	}
	return (0);
}

int	eat_stop(t_para *para)
{
	int	i;

	i = 1;
	if (para->n_meal == -1)
		return (0);
	while (i <= para->n_philo)
	{
		if (para->philo[i].p_meal < para->n_meal)
			return (0);
		else
			i++;
	}
	para->stop = 1;
	return (1);
}

void	mutexes_destroye(t_para *para, t_philo *philo)
{
	int i;

	i = 0;
	while (++i < para->n_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = 0;
	while (++i < para->n_philo)
		pthread_mutex_destroy(&(para->forks[i]));
	pthread_mutex_destroy(&(para->lock));
}

void	*life(void *philo)
{
	t_philo	*phil;
	t_para	*para;

	phil = (t_philo *)philo;
	para = phil->para;
	if (phil->philo_id % 2)
		usleep(10000);
	while (!check_dead(philo) && !eat_stop(para))
	{
		print_eat(philo);
		if (para->stop == 1)
			return (NULL);
		print_action(philo, " is sleeping");
		if (para->stop == 1)
			return (NULL);
		minisleep(para->sleep_t, philo);
		if (para->stop == 1)
			return (NULL);
		print_action(philo, " is thinking");
		if (para->stop == 1)
			return (NULL);
	}
	return (NULL);
}

int	start(t_para *para)
{
	int i;
	t_philo	*phi;

	i = 0;
	phi = para->philo;
	para->time_start = timer();
	para->stop = 0;
	while (++i <= para->n_philo)
	{
		para->philo[i].last_meal = para->time_start;
		if (pthread_create(&para->philo[i].thread_id,
				NULL, &life, &para->philo[i]) != 0)
		{
			printf("Error on thread creation\n");
			return (0);
		}
	}
	i = 1;
	while (i <= para->n_philo)
	{
		pthread_join(para->philo[i].thread_id, NULL);
		i++;
	}
	mutexes_destroye(para, phi);
	printf("end of simulation\n");
	return (0);
}
