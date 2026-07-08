/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:06 by nadamczy          #+#    #+#             */
/*   Updated: 2025/04/30 14:17:06 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_operations_utils(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack -> num_rrb)
	{
		rrb(stack);
		i++;
	}
	i = 0;
	while (i < stack -> num_rr)
	{
		rr(stack);
		i++;
	}
	i = 0;
	while (i < stack -> num_rrr)
	{
		rrr(stack);
		i++;
	}
}

void	ft_make_operations(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack -> num_ra)
	{
		ra(stack);
		i++;
	}
	i = 0;
	while (i < stack -> num_rb)
	{
		rb(stack);
		i++;
	}
	i = 0;
	while (i < stack -> num_rra)
	{
		rra(stack);
		i++;
	}
	ft_make_operations_utils(stack);
}

void	ft_less(t_stack *stack)
{
	if (stack -> num_ra > 0 && stack -> num_rb > 0)
	{
		while (stack -> num_ra > 0 && stack -> num_rb > 0)
		{
			stack -> num_rr++;
			stack -> num_ra--;
			stack -> num_rb--;
		}
	}
	if (stack -> num_rra > 0 && stack -> num_rrb > 0)
	{
		while (stack -> num_rra > 0 && stack -> num_rrb > 0)
		{
			stack -> num_rrr++;
			stack -> num_rra--;
			stack -> num_rrb--;
		}
	}
}

void	ft_num_of_operations(t_stack *stack, int pos_b, int pos_a)
{
	if (pos_a > 0)
		stack -> num_ra = pos_a;
	if (pos_a < 0)
		stack -> num_rra = -pos_a;
	if (pos_b > 0)
		stack -> num_rb = pos_b;
	if (pos_b < 0)
		stack -> num_rrb = -pos_b;
	ft_less(stack);
}

void	ft_reset(t_stack *stack)
{
	stack -> num_ra = 0;
	stack -> num_rb = 0;
	stack -> num_rra = 0;
	stack -> num_rrb = 0;
	stack -> num_rr = 0;
	stack -> num_rrr = 0;
}
