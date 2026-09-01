/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:45 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:05 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(va_list args)
{
	unsigned int	i;
	int				count;
	char			*temp;
	char			*num;

	i = va_arg(args, unsigned int);
	count = 0;
	num = ft_utoa(i);
	if (!num)
		return (ft_print_s("null"));
	temp = num;
	while (*num)
	{
		write(1, num, 1);
		num++;
		count++;
	}
	free(temp);
	return (count);
}
