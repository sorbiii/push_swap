/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:46 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/01 14:51:02 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
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
	write(1, "rrr\n", 4);
}

void	ft_adding_to_stack_a(t_stack *stack, int num, int index)
{
	stack -> stack_a[index] = num;
}

int	ft_free(t_stack *stack)
{
	free(stack -> stack_a);
	free(stack -> stack_b);
	free(stack -> cheap_array);
	free(stack);
	exit(1);
	return (write(2, "Error\n", 6));
}

int	rotation_cost(int size, int index)
{
	if (index <= size / 2)
		return (index);
	return (index - size);
}

int	ft_utils_main(t_stack *stack)
{
	free(stack -> stack_a);
	free(stack -> stack_b);
	free(stack);
	return (0);
}
