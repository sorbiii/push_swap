/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:43 by nadamczy          #+#    #+#             */
/*   Updated: 2025/04/30 14:17:43 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack -> size_a < 2)
		return ;
	i = 0;
	temp = stack -> stack_a[i];
	while (i < stack -> size_a - 1)
	{
		stack -> stack_a[i] = stack -> stack_a[i + 1];
		i++;
	}
	stack -> stack_a[stack -> size_a - 1] = temp;
	stack -> num_of_moves++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack -> size_b < 2)
		return ;
	i = 0;
	temp = stack -> stack_b[i];
	while (i < stack -> size_b - 1)
	{
		stack -> stack_b[i] = stack -> stack_b[i + 1];
		i++;
	}
	stack -> stack_b[stack -> size_b - 1] = temp;
	stack -> num_of_moves++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack -> size_a < 2)
		return ;
	i = 0;
	temp = stack -> stack_a[i];
	while (i < stack -> size_a - 1)
	{
		stack -> stack_a[i] = stack -> stack_a[i + 1];
		i++;
	}
	stack -> stack_a[stack -> size_a - 1] = temp;
	if (stack -> size_b < 2)
		return ;
	i = 0;
	temp = stack -> stack_b[i];
	while (i < stack -> size_b - 1)
	{
		stack -> stack_b[i] = stack -> stack_b[i + 1];
		i++;
	}
	stack -> stack_b[stack -> size_b - 1] = temp;
	stack -> num_of_moves++;
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack -> size_a < 2)
		return ;
	i = stack -> size_a - 1;
	temp = stack -> stack_a[i];
	while (i > 0)
	{
		stack -> stack_a[i] = stack -> stack_a[i - 1];
		i--;
	}
	stack -> stack_a[i] = temp;
	stack -> num_of_moves++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int		temp;
	size_t	i;

	if (stack -> size_b < 2)
		return ;
	i = stack -> size_b - 1;
	temp = stack -> stack_b[i];
	while (i > 0)
	{
		stack -> stack_b[i] = stack -> stack_b[i - 1];
		i--;
	}
	stack -> stack_b[i] = temp;
	stack -> num_of_moves++;
	write(1, "rrb\n", 4);
}
