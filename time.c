#include "includes/philo.h"

void ft_usleep(long int time_in_ms)
{
    long int start_time;

    start_time = 0;
    start_time = actual_time();
    while((actual_time() - start_time) < time_in_ms)
        usleep(time_in_ms / 10);
}

long int actual_time()
{
    static time_t  time_start = -1;
    long int time;
    struct timeval current_time;

    if (time_start == -1)
    {
        gettimeofday(&current_time, NULL);
        time_start = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    }
    time = 0;
    if(gettimeofday(&current_time, NULL) == -1)
        ft_exit("Gettimeofday returned -1\n");
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return(time - time_start);
}