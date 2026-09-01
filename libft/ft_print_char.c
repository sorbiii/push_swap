/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:22 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:14 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	x;

	x = (char)va_arg(args, int);
	if (x != '\n')
	{
		write(1, &x, 1);
		return (1);
	}
	else
		return (ft_print_s("(null)"));
}
