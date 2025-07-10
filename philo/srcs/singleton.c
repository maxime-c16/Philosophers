/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:17:52 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/10 16:27:32 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Philosophers.h"

t_data	*_data(void)
{
	static t_data	data;
	static bool		initialized = false;

	if (!initialized)
	{
		ft_bzero(&data, sizeof(t_data));
		initialized = true;
	}
	return (&data);
}
