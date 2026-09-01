/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:41:06 by nadamczy          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:05 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_digits(int n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_value(int num)
{
	if (num < 0)
	{
		num *= (-1);
	}
	return (num);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	sign;
	char	*new_str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
		sign = 1;
	n = ft_value(n);
	len = ft_calc_digits(n);
	new_str = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!new_str)
		return (NULL);
	new_str[len + sign] = '\0';
	if (sign == 1)
		new_str[0] = '-';
	while (len > 0)
	{
		new_str[len + sign - 1] = (n % 10 + '0');
		n /= 10;
		len--;
	}
	return (new_str);
}

/* int	main(void)
{
 	printf("%s\n", ft_itoa(34));
 	return (0);
}*/
