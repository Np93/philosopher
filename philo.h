/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:28:11 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/25 17:28:14 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct	s_philo
{
	pthread_t	thread_id;
	int	philo_id;
	int	fork_left;
	int	fork_right;
	int	p_dead;
	int	p_meal;
	char	status;
	long	last_meal;
	struct	s_para	*para;
}	t_philo;

typedef struct	s_para
{
	int	n_philo;
	int	dead;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	n_meal;
	int	stop;
	long	time_start;
	t_philo	philo[250];
	pthread_mutex_t	forks[250];
	pthread_mutex_t	lock;
}	t_para;

int	main(int argv, char **argc);
int	verifnumarg(char **argv);
long long	timer(void);
int	start(t_para *para);
void	print_eat(t_philo *philo);
int	print_action(t_philo *philo, char *action);
void	minisleep(long action, t_philo *philo);
int	ft_atoi(const char *str);
int	init(t_para *para, char **argv);
int	ft_strstr(char *str, char *tofind);
int	check_dead(t_philo *philo);
int	ft_strlen(char *str);

#endif
