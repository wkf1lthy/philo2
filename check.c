#include "includes/philo.h"


int	check_death(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->pa->dead_mutex);
	if (i)
		ph->pa->stop = i;
	if (ph->pa->stop)
	{
		pthread_mutex_unlock(&ph->pa->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&ph->pa->dead_mutex);
	return (0);
}

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death(p->ph, 0))
		ft_usleep(1);
	while (++i < p->a.philos)
	{
		pthread_join(p->ph[i].thread_id, NULL);
	}
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.philos)
	{
		pthread_mutex_destroy(&p->ph[i].left_fork);
	}
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.meals);
	free(p->ph);
}

int	ft_exit(char *str)
{
	printf("Error : ");
	printf("%s\n", str);
	printf("./philo [Philos] [Die] [Eat] [Sleep] [Meals]\n");
	return (0);
}