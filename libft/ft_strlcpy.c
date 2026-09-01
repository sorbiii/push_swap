/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:47:52 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:47:55 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t num)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (num > 0)
	{
		while (i < num - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/*int main()
{
	char str_1[10] = "Hello";
	char str_2[10] = "World";
	ft_strlcpy(str_1, str_2, 10);
	printf("%s", str_1);
	//printf("%ld", ft_strlcpy(str_1, str_2, 3));
	return (0);
}*/
