/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:58:09 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/10 16:25:33 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		ft_putstr_fd("Error: Failed to get current time.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	get_time_diff(int start_time)
{
	return (get_time() - start_time);
}

void	ft_usleep(int time)
{
	int	hit;

	hit = get_time() + time;
	while (get_time() < hit)
	{
		if (_data()->is_dead)
			return ;
		usleep(10);
	}
}
