/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:14:38 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 10:57:09 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

void	one_philo(t_data *data)
{
	mutex_message(FORK, data->philos);
	ft_usleep(data->time_to_die);
	mutex_message(DEAD, data->philos);
	free_resources(data);
}

void	mutex_message(char *msg, t_philo *philo)
{
	int	time;

	time = get_time();
	sem_wait(philo->data->message_s);
	if (is_dead(philo))
	{
		sem_post(philo->data->message_s);
		return ;
	}
	printf("%d %d %s\n",
		time - philo->data->start_time, philo->id, msg);
	sem_post(philo->data->message_s);
}
