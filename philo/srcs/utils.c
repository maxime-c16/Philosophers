/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:14:38 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 10:40:20 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

void	mutex_message(char *msg, t_philo *philo)
{
	int	time;

	time = get_time();
	pthread_mutex_lock(&philo->data->message_m);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->message_m);
		return ;
	}
	printf("%d %d %s\n",
		time - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->message_m);
}
