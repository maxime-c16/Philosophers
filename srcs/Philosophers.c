/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:25:57 by macauchy          #+#    #+#             */
/*   Updated: 2025/06/27 12:16:27 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"
#include <fcntl.h>

static void	init_data(t_data *data, const char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
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
}

static void	init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = get_time();
	sem_unlink("/philo_forks");
	sem_unlink("/philo_message");
	sem_unlink("/philo_dead");
	sem_unlink("/philo_eat");
	sem_unlink("/philo_mutex");
	data->forks_s = sem_open("/philo_forks", O_CREAT, 0644, data->num_philos / 2);
	data->message_s = sem_open("/philo_message", O_CREAT, 0644, 1);
	data->dead_s = sem_open("/philo_dead", O_CREAT, 0644, 1);
	data->eat_s = sem_open("/philo_eat", O_CREAT, 0644, 1);
	data->mutex_s = sem_open("/philo_mutex", O_CREAT, 0644, 1);
	if (data->forks_s == SEM_FAILED || data->message_s == SEM_FAILED
		|| data->dead_s == SEM_FAILED || data->eat_s == SEM_FAILED
		|| data->mutex_s == SEM_FAILED)
	{
		ft_putstr_fd("Error: sem_open() failed\n", 2);
		free_resources(data);
		exit(EXIT_FAILURE);
	}
	while (i < (size_t)data->num_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].die_soon = 0;
		if (pthread_create(&data->philos[i].thread, NULL,
			philo_routine, &data->philos[i]) != 0)
		{
			ft_putstr_fd("Error: Failed to create philosopher thread.\n", 2);
			free_resources(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
	if (data.num_philos == 1)
		return (one_philo(&data), 0);
	monitoring(&data);
	join_threads(&data);
	free_resources(&data);
	return (0);
}