/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:39:08 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/26 12:29:40 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

static bool	check_philo(t_data *data, size_t i)
{
	sem_wait(data->mutex_s);
	if (data->philos[i].meals_eaten >= data->num_meals
		&& data->num_meals > 0)
	{
		data->has_eaten++;
		if (data->has_eaten == data->num_philos)
		{
			data->is_dead = true;
			sem_post(data->mutex_s);
			return (false);
		}
	}
	sem_post(data->mutex_s);
	return (true);
}

static bool	philo_die(t_philo *philo)
{
	sem_wait(philo->data->dead_s);
	printf("%dms\t : Philosopher %d %s\n",
		get_time_diff(philo->data->start_time), philo->id, DEAD);
	philo->data->is_dead = true;
	sem_post(philo->data->dead_s);
	return (true);
}

static bool	kill_philo(t_philo *philo)
{
	sem_wait(philo->data->message_s);
	sem_wait(philo->data->mutex_s);
	if (get_time_diff(philo->data->start_time) - philo->last_meal
		> philo->data->time_to_die)
	{
		philo_die(philo);
		sem_post(philo->data->mutex_s);
		sem_post(philo->data->message_s);
		return (false);
	}
	sem_post(philo->data->mutex_s);
	sem_post(philo->data->message_s);
	return (true);
}

bool	monitoring(t_data *data)
{
	size_t	i;

	while (true)
	{
		i = 0;
		data->has_eaten = 0;
		while (i < (size_t)data->num_philos)
		{
			if (!check_philo(data, i))
				return (false);
			if (!kill_philo(&data->philos[i]))
				return (false);
			usleep(400);
			i++;
		}
	}
}