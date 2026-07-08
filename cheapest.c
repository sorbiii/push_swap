/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:18:11 by nadamczy          #+#    #+#             */
/*   Updated: 2025/04/30 14:19:02 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max(const int *stack_b, int size_b, int *max, int *max_index)
{
	int	i;

	i = 0;
	*max = stack_b[0];
	*max_index = 0;
	while (i < size_b)
	{
		if (stack_b[i] > *max)
		{
			*max = stack_b[i];
			*max_index = i;
		}
		i++;
	}
}

int	find_position_in_b_desc(int *stack_b, int size_b, int value)
{
	int	candidate;
	int	candidate_index;
	int	max;
	int	max_index;
	int	i;

	i = 0;
	candidate = INT_MIN;
	candidate_index = -1;
	find_max(stack_b, size_b, &max, &max_index);
	while (i < size_b)
	{
		if (stack_b[i] < value && stack_b[i] > candidate)
		{
			candidate = stack_b[i];
			candidate_index = i;
		}
		i++;
	}
	if (candidate_index == -1)
		return (max_index);
	else
		return (candidate_index);
}

int	ft_sub_absolut_value(int a, int b)
{
	int	sub;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		sub = a;
	else
		sub = b;
	return (sub);
}

int	ft_utils_for_computing(int cost_a, int cost_b, int total)
{
	if (cost_a == cost_b)
	{
		if (cost_a > 0)
			total = cost_a + 1;
		else
			total = -cost_a + 1;
	}
	else if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		total = ft_sub_absolut_value(cost_a, cost_b) + 1;
	else
	{
		if (cost_a < 0)
			cost_a = -cost_a;
		if (cost_b < 0)
			cost_b = -cost_b;
		total = cost_a + cost_b + 1;
	}
	return (total);
}

void	ft_compute_moves_for_all(t_stack *stack)
{
	int	i;
	int	total;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	i = 0;
	while (i < (int)stack -> size_a)
	{
		total = 0;
		pos_b = find_position_in_b_desc(stack->stack_b, stack->size_b,
				stack->stack_a[i]);
		cost_a = rotation_cost(stack -> size_a, i);
		cost_b = rotation_cost(stack -> size_b, pos_b);
		total = ft_utils_for_computing(cost_a, cost_b, total);
		stack -> cheap_array[i] = total;
		i++;
	}
}
