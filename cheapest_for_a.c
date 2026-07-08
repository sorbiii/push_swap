/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_for_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:23 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/02 16:39:20 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_a_for_b(t_stack *stack, int value_b)
{
	int	i;
	int	candidate;
	int	candidate_index;
	int	min_index;

	candidate = INT_MAX;
	candidate_index = -1;
	min_index = 0;
	i = 0;
	while (i < (int)stack -> size_a)
	{
		if (stack -> stack_a[i] < stack -> stack_a[min_index])
			min_index = i;
		if (stack -> stack_a[i] > value_b
			&& (stack -> stack_a[i] < candidate || candidate == INT_MAX))
		{
			candidate = stack -> stack_a[i];
			candidate_index = i;
		}
		i++;
	}
	if (candidate_index == -1)
		return (min_index);
	else
		return (candidate_index);
}

void	ft_num_of_operations_a(t_stack *stack, int pos_a)
{
	if (pos_a > 0)
		stack -> num_ra = pos_a;
	if (pos_a < 0)
		stack -> num_rra = -pos_a;
}

int	small_candidate(t_stack *stack, int candidate, int candidate_index)
{
	int	i;

	i = 0;
	while (i < (int)stack -> size_a)
	{
		if (stack -> stack_a[i] < candidate)
		{
			candidate = stack -> stack_a[i];
			candidate_index = i;
		}
		i++;
	}
	return (candidate_index);
}

void	ft_small_a_to_top(t_stack *stack)
{
	int	candidate;
	int	candidate_index;

	candidate = INT_MAX;
	candidate_index = -1;
	candidate_index = small_candidate(stack, candidate, candidate_index);
	candidate = rotation_cost(stack -> size_a, candidate);
	if (candidate_index > 0)
	{
		while (candidate_index > 0)
		{
			ra(stack);
			candidate_index--;
		}
	}
	else if (candidate_index < 0)
	{
		while (candidate_index < 0)
		{
			rra(stack);
			candidate_index++;
		}
	}
}

void	ft_turk_for_a(t_stack *stack)
{
	int	position_num_a;

	while (stack -> size_b > 0)
	{
		position_num_a = find_position_a_for_b(stack, stack -> stack_b[0]);
		position_num_a = rotation_cost(stack -> size_a, position_num_a);
		ft_num_of_operations_a(stack, position_num_a);
		ft_make_operations(stack);
		ft_reset(stack);
		pa(stack);
	}
	ft_small_a_to_top(stack);
}
