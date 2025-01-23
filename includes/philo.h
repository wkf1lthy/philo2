#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_stats
{
	int				philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				number_philos_ate;
	int				stop;
	long int		start_t;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	time_eat_mutex;
	pthread_mutex_t	finish_mutex;
}					t_stats;

typedef struct s_philo
{
	int				id;
	int				finish;
	long int		ms_eat;
	unsigned int	nb_philo_ate;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	t_stats			*pa;
}					t_philo;

typedef struct s_p
{
	t_philo			*ph;
	t_stats			a;
}					t_p;

int					ft_strlen(char *str);
int					ft_atoi(const char *str);
int					is_number(char **argv, int i, int j);
int					args(int argc, char **argv, t_p *p);
void				ft_usleep(long int time_in_ms);
int					check_death(t_philo *ph, int i);
long int			actual_time(void);
void				stop(t_p *p);
void				simulation(t_philo *ph);
void				sleep_and_think(t_philo *ph);
void				print_status(char *str, t_philo *ph);
int					ft_exit(char *str);
void				*is_dead(void *data);
void				*thread(void *data);
int					threading(t_p *p);
int					initialize(t_p *p);
void				init_mutex(t_p *p);

#endif