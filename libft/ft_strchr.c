/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:32:24 by maximecauch       #+#    #+#             */
/*   Updated: 2025/04/24 16:31:42 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if ((char)c == '\0')
		return (ptr + i);
	return (NULL);
}
