/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:25:57 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/25 18:02:38 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

static void	init_data(t_data *data, const char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->num_philos = ft_atoi(av[4]);
	if (av[5])
		data->num_meals = ft_atoi(av[5]);
	else
		data->num_meals = -1;
	data->is_dead = false;
	data->start_time = 0;
	data->has_eaten = false;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		ft_putstr_fd("Error: Memory allocation failed for philosophers.\n", 2);
		exit(EXIT_FAILURE);
	}
	data->forks_m = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks_m)
	{
		ft_putstr_fd("Error: Memory allocation failed for forks.\n", 2);
		free(data->philos);
		exit(EXIT_FAILURE);
	}
}

static void	init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = get_time();
	while (i < (size_t)data->num_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].die_soon = 0;
		data->philos[i].left_fork = &data->forks_m[i];
		data->philos[i].right_fork = &data->forks_m[(i + 1) % data->num_philos];
		pthread_mutex_init(&data->forks_m[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->message_m, NULL);
	pthread_mutex_init(&data->dead_m, NULL);
	pthread_mutex_init(&data->eat_m, NULL);
	pthread_mutex_init(&data->mutex_m, NULL);
}

static bool	check_args(int ac, char **av)
{
	size_t	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		ft_putstr_fd(
			"Usage: ./philo <time_to_die> <time_to_eat> <time_to_sleep> "
			"<num_philos> [num_meals]\n", 2);
		return (false);
	}
	while (i < (size_t)ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			ft_putstr_fd(
				"Error: All arguments must be positive integers.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;
	if (!check_args(ac, av))
		return (1);
	init_data(&data, (const char **)av);
	init_philo(&data);
	join_threads(&data);
	free_resources(&data);
	return (0);
}
