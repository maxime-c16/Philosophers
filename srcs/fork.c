/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:19:59 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 10:20:36 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

static pthread_mutex_t	*get_first_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return philo->right_fork;
	else
		return philo->left_fork;
}

static pthread_mutex_t	*get_second_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return philo->left_fork;
	else
		return philo->right_fork;
}

static void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_t *first_fork = get_first_fork(philo);
	pthread_mutex_t *second_fork = get_second_fork(philo);

	pthread_mutex_lock(first_fork);
	mutex_message(FORK, philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(first_fork);
		return ;
	}
	pthread_mutex_lock(second_fork);
	mutex_message(FORK, philo);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return ;
	}
	philo_eat(philo);
	unlock_forks(philo);
}
