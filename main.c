#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_p		p;

	if (!(args(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.philos);
	if (!p.ph)
		return (ft_exit("Malloc returned NULL\n"));
	if (!initialize(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
	return (0);
}