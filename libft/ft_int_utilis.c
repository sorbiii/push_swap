/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utilis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:17 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:15 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calc_udigits(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	size_t	len;
	char	*new_str;

	len = ft_calc_udigits(n);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	while (len > 0)
	{
		new_str[len - 1] = (n % 10 + '0');
		n /= 10;
		len--;
	}
	return (new_str);
}

int	ft_calc_digits(int n)
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
