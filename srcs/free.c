/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:25:50 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/08 10:18:12 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

static void	check_and_destroy_mutex(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->num_philos)
	{
		pthread_mutex_destroy(&data->forks_m[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_m);
	pthread_mutex_destroy(&data->eat_m);
	pthread_mutex_destroy(&data->message_m);
}

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
	check_and_destroy_mutex(data);
	if (data->philos)
		free(data->philos);
	if (data->forks_m)
		free(data->forks_m);
}
