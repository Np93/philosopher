/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:27:57 by nhirzel           #+#    #+#             */
/*   Updated: 2022/02/25 17:27:59 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	the_one(t_para *para)
{
	usleep(para->die_t);
	printf("%d : 1 died\n", para->die_t);
	printf("end of simulation\n");
}

void	too_much_main(void)
{
	printf("usage : ./philo [n of philo] [time to die] [time to eat]");
	printf(" [time to sleep] ([number of meals])\n");
}

int	main(int argc, char **argv)
{
	t_para	para;

	if ((argc != 5 && argc != 6) || verifnumarg(argv) == 0)
	{
		too_much_main();
		return (0);
	}
	if (!init(&para, argv))
		return (0);
	if (para.n_philo > 249)
	{
		printf("too much philo\n");
		return (0);
	}
	if (para.n_philo == 1)
	{
		the_one(&para);
		return (0);
	}
	else if (!start(&para))
		return (0);
	return (0);
}
