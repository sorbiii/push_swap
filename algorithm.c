/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:15 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/02 20:16:18 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_turk_start(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack -> stack_b[0];
	b = stack -> stack_b[1];
	c = stack -> stack_b[2];
	if (a > b && b > c)
		return ;
	else if (a > c && c > b)
	{
		rrb(stack);
		sb(stack);
	}
	else if (b > a && a > c)
		sb(stack);
	else if (b > c && c > a)
		rb(stack);
	else if (c > a && a > b)
		rrb(stack);
	else if (c > b && b > a)
	{
		sb(stack);
		rrb(stack);
	}
}

void	ft_turk(t_stack *stack)
{
	int	i;
	int	least_moves;
	int	index_a;
	int	position_num_b;

	i = 1;
	index_a = 0;
	least_moves = stack -> cheap_array[0];
	while (i < (int)stack -> size_a)
	{
		if (stack -> cheap_array[i] < least_moves)
		{
			least_moves = stack -> cheap_array[i];
			index_a = i;
		}
		i++;
	}
	position_num_b = find_position_in_b_desc(stack -> stack_b,
			stack -> size_b, stack -> stack_a[index_a]);
	index_a = rotation_cost(stack -> size_a, index_a);
	position_num_b = rotation_cost(stack -> size_b, position_num_b);
	ft_num_of_operations(stack, position_num_b, index_a);
	ft_make_operations(stack);
	ft_reset(stack);
	pb(stack);
}

int	first_check(t_stack *stack)
{
	if (stack->size_a + stack->size_b <= 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa(stack);
		return (1);
	}
	else if (stack->size_a + stack->size_b == 3)
	{
		ft_sort_three_elem(stack);
		return (1);
	}
	else if (stack->size_a + stack->size_b == 5)
	{
		ft_sort_five_elem(stack);
		return (1);
	}
	return (0);
}

void	ft_last_from_a(t_stack *stack)
{
	if (stack -> size_a == 4)
		ft_sort_four_elem(stack);
	else if (stack -> size_a == 3)
		ft_sort_three_elem(stack);
	else if (stack -> size_a == 2)
	{
		if (stack -> stack_a[0] > stack -> stack_a[1])
			sa(stack);
	}
}

void	ft_algorithm(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (first_check(stack) == 1)
		return ;
	if (stack->size_b == 0)
	{
		pb(stack);
		pb(stack);
		pb(stack);
		ft_turk_start(stack);
	}
	while (stack->size_a > 4)
	{
		ft_compute_moves_for_all(stack);
		ft_turk(stack);
		free(stack->cheap_array);
		stack->cheap_array = ft_calloc(stack->size_a, sizeof(int));
	}
	free(stack -> cheap_array);
	ft_last_from_a(stack);
	ft_turk_for_a(stack);
}
