/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:39:34 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/02 16:11:44 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_change_sign(int sign, long value)
{
	if (sign == 1)
	{
		value = -value;
	}
	return ((int)value);
}

static long	ft_limit(int sign)
{
	if (sign == 1)
		return (((long int)INT_MAX) + 1);
	else
		return (INT_MAX);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	value;
	int		sign;
	long	limit;

	i = 0;
	value = 0;
	sign = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-' && (nptr[i + 1] >= 48 && nptr[i + 1] <= 57))
			sign = 1;
		i++;
	}
	limit = ft_limit(sign);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (value > (limit - (nptr[i] - '0')) / 10)
			return (0);
		value = (value * 10) + (nptr[i] - '0');
		i++;
	}
	return (ft_change_sign(sign, value));
}
