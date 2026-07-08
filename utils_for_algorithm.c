/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:52 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/22 11:54:40 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_elem(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack -> stack_a[0];
	b = stack -> stack_a[1];
	c = stack -> stack_a[2];
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(stack);
		ra(stack);
	}
	else if (b < a && a < c)
		sa(stack);
	else if (b < c && c < a)
		ra(stack);
	else if (c < a && a < b)
		rra(stack);
	else if (c < b && b < a)
	{
		sa(stack);
		rra(stack);
	}
}

int	ft_is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (stack->size_a == 1)
		return (0);
	while (i + 1 < stack -> size_a)
	{
		if ((stack -> stack_a[i] < stack -> stack_a[i + 1])
			&& (stack -> size_b == 0))
			i++;
		else
			return (0);
	}
	return (1);
}

int	find_min_index(int *stack, size_t size)
{
	int	i;
	int	min_index;
	int	min;

	min_index = 0;
	min = stack[0];
	i = 1;
	while (i < (int)size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	ft_sort_four_elem(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack->stack_a, stack->size_a);
	if (min_index == 1)
		ra(stack);
	else if (min_index == 2)
	{
		ra(stack);
		ra(stack);
	}
	else if (min_index == 3)
		rra(stack);
	pb(stack);
	ft_sort_three_elem(stack);
	pa(stack);
}
