/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:49:13 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 14:29:49 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == '\0' && c == '\0')
	{
		return ((char *)&str[i]);
	}
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
}

/*int main(void)
{
	char stringus[10] = "hhfhfd";
	int c = 'f';
	printf("%p\n", ft_strrchr(stringus, c));
	printf("%p", strrchr(stringus, c));
}*/
