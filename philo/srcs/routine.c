/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:13:35 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/10 16:25:42 by macauchy         ###   ########.fr       */
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

void	philo_eat(t_philo *philo)
{
	int	time;

	time = get_time_diff(philo->data->start_time);
	pthread_mutex_lock(&philo->data->message_m);
	if (is_dead(philo) || philo->meals_eaten == philo->data->num_meals)
	{
		pthread_mutex_unlock(&philo->data->message_m);
		return ;
	}
	printf("%d %d %s\n", time, philo->id, EAT);
	pthread_mutex_unlock(&philo->data->message_m);
	pthread_mutex_lock(&philo->data->mutex_m);
	philo->last_meal = time;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->mutex_m);
	ft_usleep(philo->data->time_to_eat);
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
