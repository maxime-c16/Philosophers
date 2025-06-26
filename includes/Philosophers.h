/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:46:37 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/26 15:18:01 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>

# include "../libft/libft.h"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct	s_philo
{
	int				id;
	int				last_meal;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				die_soon;
	struct s_data	*data;
}	t_philo;

typedef struct	s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philos;
	int				num_meals;
	bool			is_dead;
	int				start_time;
	int				has_eaten;
	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	message_m;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	mutex_m;
}	t_data;

void	free_resources(t_data *data);
void	join_threads(t_data *data);

int		get_time_diff(int start_time);
int		get_time(void);

bool	monitoring(t_data *data);
bool	is_dead(t_philo *philo);

void	*philo_routine(void *philosophs);

void	mutex_message(char *msg, t_philo *philo);

#endif
