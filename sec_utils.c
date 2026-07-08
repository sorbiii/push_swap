/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:20 by nadamczy          #+#    #+#             */
/*   Updated: 2025/04/30 14:29:25 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	free_everything(char **arguments, t_stack *stack)
{
	ft_free_split(arguments);
	return (ft_free(stack));
}

int	ft_check_for_duplicates(t_stack *stack, int num, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		if (stack -> stack_a[j] == num)
			return (0);
		j++;
	}
	return (1);
}
