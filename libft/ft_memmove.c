/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:42:48 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:01 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	else if (!(dest > src && dest < src + n))
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(char *)(dest + i) = *(char *)(src + i);
		}
	}
	return (dest);
}

/*int main()
{
	char str[10] = "ptpipipipi";
	ft_memmove(str + 1, str, 2);
	printf("%s", str);
	return 0;
}*/
