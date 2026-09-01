/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:02 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:19 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_value(int num)
{
	if (num < 0)
	{
		num *= (-1);
	}
	return (num);
}

int	ft_print_s(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	ft_calc_digits_hex(unsigned int i)
{
	int	digits;

	digits = 0;
	if (i == 0)
		return (1);
	while (i >= 1)
	{
		i /= 16;
		digits++;
	}
	return (digits);
}
