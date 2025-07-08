/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:39:08 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 10:40:20 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

int	single_philo(t_data *data)
{
	printf("0 %d %s\n",
		data->philos[0].id, FORK);
	ft_usleep(data->time_to_die);
	printf("%d %d %s\n",
		data->time_to_die, data->philos[0].id, DEAD);
	free_resources(data);
	return (0);
}

static bool	check_philo(t_data *data, size_t i)
{
	pthread_mutex_lock(&data->mutex_m);
	if (data->philos[i].meals_eaten >= data->num_meals
		&& data->num_meals > 0)
	{
		data->has_eaten++;
		if (data->has_eaten == data->num_philos)
		{
			data->is_dead = true;
			pthread_mutex_unlock(&data->mutex_m);
			return (false);
		}
	}
	pthread_mutex_unlock(&data->mutex_m);
	return (true);
}

static bool	philo_die(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->dead_m) != 0)
	{
		ft_putstr_fd("Error: Failed to lock dead mutex.\n", 2);
		return (false);
	}
	printf("%d %d %s\n",
		get_time_diff(philo->data->start_time), philo->id, DEAD);
	philo->data->is_dead = true;
	if (pthread_mutex_unlock(&philo->data->dead_m) != 0)
	{
		ft_putstr_fd("Error: Failed to unlock dead mutex.\n", 2);
		return (false);
	}
	return (true);
}

static bool	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message_m);
	pthread_mutex_lock(&philo->data->mutex_m);
	if (get_time_diff(philo->data->start_time) - philo->last_meal
		> philo->data->time_to_die)
	{
		philo_die(philo);
		pthread_mutex_unlock(&philo->data->mutex_m);
		pthread_mutex_unlock(&philo->data->message_m);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->mutex_m);
	pthread_mutex_unlock(&philo->data->message_m);
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
