#include "includes/philo.h"

void	print_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = actual_time() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
	{
		printf("%ld ms ", time);
		printf("Philo %d %s", ph->id, str);
	}
}



void	sleep_and_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time_to_sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}



void	simulation(t_philo *ph)
{
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->right_fork)
	{
		ft_usleep(ph->pa->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	print_status("is eating\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat_mutex);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->pa->time_eat_mutex);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time_to_eat);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(&ph->left_fork);
	sleep_and_think(ph);
}