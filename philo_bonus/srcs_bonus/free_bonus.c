/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:25:50 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 11:06:58 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/Philosophers_bonus.h"

void	join_threads(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data || !data->philos)
		return ;
	while (i < (size_t)data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	free_resources(t_data *data)
{
	if (!data)
		return ;
	sem_close(data->forks_s);
	sem_close(data->message_s);
	sem_close(data->dead_s);
	sem_close(data->eat_s);
	sem_close(data->mutex_s);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_message");
	sem_unlink("/philo_dead");
	sem_unlink("/philo_eat");
	sem_unlink("/philo_mutex");
	if (data->philos)
		free(data->philos);
}
