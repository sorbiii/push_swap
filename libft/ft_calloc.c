/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:40:15 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 15:22:00 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t			i;
	unsigned char	*space;

	i = nmeb * size;
	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	if (nmeb > INT_MAX / size)
	{
		return (NULL);
	}
	space = malloc(i);
	if (!space)
	{
		return (NULL);
	}
	ft_bzero(space, i);
	return (space);
}
