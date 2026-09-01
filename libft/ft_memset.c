/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:34:54 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:00 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new_ptr;
	size_t			i;

	new_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_ptr[i] = (unsigned char)c;
		i++;
	}
	return (new_ptr);
}
