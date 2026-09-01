/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:54 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:16:58 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count_args;
	char	*str;

	if (!format || *format == '\0')
	{
		return (0);
	}
	str = ft_strdup(format);
	if (!str)
	{
		return (0);
	}
	va_start(args, format);
	count_args = ft_argument_to_print(args, (char *)format);
	va_end(args);
	free(str);
	return (count_args);
}
