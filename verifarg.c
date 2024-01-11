#include "philo.h"

int	isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == 43)
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	verifnumarg(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (isnum(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
