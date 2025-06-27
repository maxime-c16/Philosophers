/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:13:35 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/27 12:02:18 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

bool	is_dead(t_philo *philo)
{
	sem_wait(philo->data->dead_s);
	if (philo->data->is_dead)
	{
		sem_post(philo->data->dead_s);
		return (true);
	}
	sem_post(philo->data->dead_s);
	return (false);
}

static void	philo_eat(t_philo *philo)
{
	int	time;

	time = get_time_diff(philo->data->start_time);
	sem_wait(philo->data->message_s);
	if (is_dead(philo))
	{
		sem_post(philo->data->message_s);
		return ;
	}
	printf("%dms\t : Philosopher %d %s\n", time, philo->id, EAT);
	sem_post(philo->data->message_s);
	sem_wait(philo->data->mutex_s);
	philo->last_meal = get_time() - philo->data->start_time;
	philo->meals_eaten++;
	sem_post(philo->data->mutex_s);
	ft_usleep(philo->data->time_to_eat);
}

static void	take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks_s);
	mutex_message(FORK, philo);
	if (is_dead(philo))
	{
		sem_post(philo->data->forks_s);
		return ;
	}
	sem_wait(philo->data->forks_s);
	mutex_message(FORK, philo);
	philo_eat(philo);
	sem_post(philo->data->forks_s);
	sem_post(philo->data->forks_s);
}

static void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	mutex_message(SLEEP, philo);
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
		mutex_message(THINK, philo);
		usleep(200);
	}
	return (NULL);
}