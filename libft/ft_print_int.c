/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:27 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:13 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args)
{
	int		i;
	int		count;
	char	*num;
	char	*temp;

	i = va_arg(args, int);
	count = 0;
	num = ft_itoa(i);
	if (!num)
		return (ft_print_s("(null)"));
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
