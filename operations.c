/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:59 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/02 20:20:10 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack -> size_a < 2)
		return ;
	temp = stack -> stack_a[0];
	stack -> stack_a[0] = stack -> stack_a[1];
	stack -> stack_a[1] = temp;
	stack -> num_of_moves++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack -> size_a < 2)
		return ;
	temp = stack -> stack_b[0];
	stack -> stack_b[0] = stack -> stack_b[1];
	stack -> stack_b[1] = temp;
	stack -> num_of_moves++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	int	temp_a;
	int	temp_b;

	if (stack -> size_a < 2)
		return ;
	temp_a = stack -> stack_a[0];
	stack -> stack_a[0] = stack -> stack_a[1];
	stack -> stack_a[1] = temp_a;
	if (!stack -> stack_b[1])
		return ;
	temp_b = stack -> stack_b[0];
	stack -> stack_b[0] = stack -> stack_b[1];
	stack -> stack_b[1] = temp_b;
	stack -> num_of_moves++;
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack)
{
	size_t	i;

	if (stack -> size_b == 0)
		return ;
	i = stack -> size_a;
	while (i > 0)
	{
		stack -> stack_a[i] = stack -> stack_a[i - 1];
		i--;
	}
	stack -> stack_a[0] = stack -> stack_b[0];
	stack -> size_a++;
	i = 0;
	while (i + 1 < stack -> size_b)
	{
		stack -> stack_b[i] = stack -> stack_b[i + 1];
		i++;
	}
	stack -> size_b--;
	stack -> num_of_moves++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	size_t	i;

	if (stack -> size_a == 0)
		return ;
	i = stack -> size_b;
	while (i > 0)
	{
		stack -> stack_b[i] = stack -> stack_b[i - 1];
		i--;
	}
	stack -> stack_b[0] = stack -> stack_a[0];
	stack -> size_b++;
	i = 0;
	while (i + 1 < stack -> size_a)
	{
		stack -> stack_a[i] = stack -> stack_a[i + 1];
		i++;
	}
	stack -> size_a--;
	stack -> num_of_moves++;
	write(1, "pb\n", 3);
}
