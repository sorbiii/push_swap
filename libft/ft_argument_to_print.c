/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_to_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:10 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:16 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char k, va_list args)
{
	int	count;

	count = 0;
	if (k == 'c')
		count += ft_print_char(args);
	if (k == 's')
		count += ft_print_string(args);
	if (k == 'i' || k == 'd')
		count += ft_print_int(args);
	if (k == 'u')
		count += ft_print_unsigned_int(args);
	if (k == 'x')
		count += ft_print_low_hex(args);
	if (k == 'X')
		count += ft_print_upp_hex(args);
	if (k == 'p')
		count += ft_print_pointer(args);
	return (count);
}

int	ft_argument_to_print(va_list args, char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(str[i], args);
			if (str[i] == '%')
				count += ft_print_s("%");
			i++;
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			count++;
			write(1, &str[i], 1);
		}
		if (str[i] == '%')
			i--;
		i++;
	}
	return (count);
}
