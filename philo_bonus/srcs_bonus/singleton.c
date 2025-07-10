/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:42:19 by macauchy          #+#    #+#             */
/*   Updated: 2025/07/10 16:48:00 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/Philosophers_bonus.h"

t_data	*_data(void)
{
	static t_data	data;
	static bool		init = false;

	if (!init)
	{
		ft_bzero(&data, sizeof(t_data));
		init = true;
	}
	return (&data);
}
