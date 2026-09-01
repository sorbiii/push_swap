/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:47:11 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:47:57 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dest[dest_len] != '\0' && dest_len < dsize)
		dest_len++;
	if (dest_len >= dsize)
		return (dsize + src_len);
	len = dsize - dest_len - 1;
	while (i < len && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

/*int	main(void)
{
	char str_1[10] = "Hello";
	char str_2[10] = "World";
	size_t i = strlcat(str_1, str_2, 5);
	printf("%ld", i);
}*/
