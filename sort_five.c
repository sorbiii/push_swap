/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:47:12 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/02 19:33:28 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_min_to_b(t_stack *stack)
{
	size_t	min_index;
	size_t	moves;

	min_index = find_min_index(stack->stack_a, stack->size_a);
	if (min_index <= stack->size_a / 2)
	{
		moves = min_index;
		while (moves-- > 0)
			ra(stack);
	}
	else
	{
		moves = stack->size_a - min_index;
		while (moves-- > 0)
			rra(stack);
	}
	pb(stack);
}

void	ft_sort_five_elem(t_stack *stack)
{
	ft_push_min_to_b(stack);
	ft_push_min_to_b(stack);
	ft_sort_three_elem(stack);
	pa(stack);
	pa(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}
