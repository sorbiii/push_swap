/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:42:29 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 14:01:58 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/*int main()
{
	int str_1[10] = {2, 2, 2, 2, 2};
	int str_2[10] = {4, 4, 4, 4, 4};

	ft_memcpy(str_1 + 2, str_2, 8);

	int i = 0;
	while (i < 5)
	{
		printf("%d", str_1[i]);
		i++;
	}
	return (0);
}*/
