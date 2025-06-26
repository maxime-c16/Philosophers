/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:13:35 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/26 16:07:18 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_m);
	if (philo->data->is_dead)
	{
		pthread_mutex_unlock(&philo->data->dead_m);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_m);
	return (false);
}

static void	philo_eat(t_philo *philo)
{
	int	time;

	time = get_time_diff(philo->data->start_time);
	pthread_mutex_lock(&philo->data->message_m);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->message_m);
		return ;
	}
	printf("%dms\t : Philosopher %d %s\n", time, philo->id, EAT);
	pthread_mutex_unlock(&philo->data->message_m);
	pthread_mutex_lock(&philo->data->mutex_m);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock((pthread_mutex_t *)((!(philo->id % 2)
				* (long long int)philo->right_fork) + ((philo->id % 2 != 0)
				* (long long int)philo->left_fork)));
	mutex_message(FORK, philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock((pthread_mutex_t *)((!(philo->id % 2)
				* (long long int)philo->right_fork) + ((philo->id % 2 != 0)
				* (long long int)philo->left_fork)));
		return ;
	}
	pthread_mutex_lock((pthread_mutex_t *)((!(philo->id % 2)
				* (long long int)philo->left_fork) + ((philo->id % 2 != 0)
				* (long long int)philo->right_fork)));
	mutex_message(FORK, philo);
	philo_eat(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_usleep(int time)
{
	int	hit;

	hit = get_time() + time;
	while (get_time() < hit)
		usleep(10);
}

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	mutex_message("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	*philo_routine(void *philosophs)
{
	t_philo	*philo;

	philo = (t_philo *)philosophs;
	while (!is_dead(philo))
	{
		take_fork(philo);
		if (is_dead(philo))
			return (NULL);
		philo_sleep(philo);
		if (is_dead(philo))
			return (NULL);
		mutex_message("is thinking", philo);
		usleep(200);
	}
	return (NULL);
}
