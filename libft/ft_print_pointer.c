/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:36 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:07 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calc_pointer_digits(uintptr_t temp)
{
	int	digits;

	digits = 0;
	if (temp == 0)
		return (1);
	while (temp)
	{
		temp /= 16;
		digits++;
	}
	return (digits);
}

static int	changing_dec_to_hex(char *num, unsigned int count, uintptr_t i,
		unsigned int digits)
{
	unsigned int	r;

	r = 0;
	while (count < digits)
	{
		r = i % 16;
		i /= 16;
		if (r > 9)
			num[digits - count - 1] = r + 87;
		else
			num[digits - count - 1] = r + 48;
		count++;
	}
	return (count);
}

int	ft_print_pointer(va_list args)
{
	unsigned int	digits;
	unsigned int	count;
	char			*num;
	uintptr_t		i;

	count = 0;
	i = (uintptr_t)va_arg(args, void *);
	if (!i)
		return (ft_print_s("(nil)"));
	digits = ft_calc_pointer_digits(i);
	num = malloc(digits + 1);
	if (!num)
		return (ft_print_s("(nil)"));
	num[digits] = '\0';
	count += changing_dec_to_hex(num, count, i, digits);
	write(1, "0x", 2);
	write(1, num, ft_strlen(num));
	count += 2;
	free(num);
	return (count);
}
