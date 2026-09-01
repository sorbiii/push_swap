/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:45:25 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 14:16:37 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == '\0' && c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

/*int main(void)
{
	char stringus[10] = "hfhfd";
	int c = '\0';
	printf("%p", ft_strchr(stringus, c));
}*/
