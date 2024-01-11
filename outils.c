/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:28:25 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/25 17:28:28 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	timer(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int			res;
	int			m;

	i = 0;
	m = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		m *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * m;
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strstr2(char *str, char *tofind)
{
	int	i;

	i = 0;
	while (str[i] == tofind[i] && str[i] != '\0')
		i++;
	if (tofind[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_strstr(char *str, char *tofind)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != tofind[0])
			i++;
		else
		{
			if (ft_strstr2(str + i, tofind))
				return (i + ft_strlen(tofind));
			else
				i++;
		}
	}
	return (0);
}
