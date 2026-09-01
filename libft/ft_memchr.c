/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:42:09 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:04 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t num)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		c;

	s = (const unsigned char *)str;
	c = (unsigned char)chr;
	i = 0;
	while (i < num)
	{
		if (s[i] == c)
		{
			return ((void *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	printf("%p\n", ft_memchr("huhu", 'e', 2));
	printf("%p\n", memchr("huhu", 'e', 2));
	return (0);
}*/
