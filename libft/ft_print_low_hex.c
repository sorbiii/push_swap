/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_low_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:32 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:08 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_change_value_low(unsigned int r)
{
	char	k;

	if (r > 9)
		k = r + 87;
	else
		k = r + 48;
	return (k);
}

int	ft_print_low_hex(va_list args)
{
	unsigned int	i;
	unsigned int	digits;
	char			*num;
	int				index;

	i = va_arg(args, unsigned int);
	if (i == 0)
		return (ft_print_s("0"));
	digits = ft_calc_digits_hex(i);
	num = malloc(digits + 1);
	if (num == NULL)
		return (ft_print_s("(null)"));
	index = digits - 1;
	while (i)
	{
		num[index] = ft_change_value_low(i % 16);
		i /= 16;
		index--;
	}
	num[digits] = '\0';
	write(1, num, digits);
	free(num);
	return (digits);
}
