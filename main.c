/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:40 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/22 11:51:11 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <threads.h>

void	ft_allocate_sec(t_stack **stack, int argc)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)-> size_a = argc;
	(*stack)-> size_b = 0;
	(*stack)-> stack_a = malloc(argc * sizeof(int));
	(*stack)-> stack_b = malloc(argc * sizeof(int));
	(*stack)-> cheap_array = ft_calloc((*stack)-> size_a - 3, sizeof(int));
	(*stack)-> num_ra = 0;
	(*stack)-> num_rb = 0;
	(*stack)-> num_rr = 0;
	(*stack)-> num_rra = 0;
	(*stack)-> num_rrb = 0;
	(*stack)-> num_rrr = 0;
	(*stack)-> num_of_moves = 0;
}

void	ft_allocate(t_stack **stack, int argc)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)-> size_a = argc -1;
	(*stack)-> size_b = 0;
	(*stack)-> stack_a = malloc((argc - 1) * sizeof(int));
	(*stack)-> stack_b = malloc((argc - 1) * sizeof(int));
	(*stack)-> cheap_array = ft_calloc((*stack)-> size_a - 3, sizeof(int));
	(*stack)-> num_ra = 0;
	(*stack)-> num_rb = 0;
	(*stack)-> num_rr = 0;
	(*stack)-> num_rra = 0;
	(*stack)-> num_rrb = 0;
	(*stack)-> num_rrr = 0;
	(*stack)-> num_of_moves = 0;
}

int	new_numbers_sec(t_stack *stack, int argc, char *argv[])
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (write(2, "Error\n", 6));
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (write(2, "Error\n", 6));
		if (!ft_check_for_duplicates(stack, (int)num, i))
			return (write(2, "Error\n", 6));
		ft_adding_to_stack_a(stack, (int)num, i);
		i++;
	}
	return (1);
}

int	new_numbers(t_stack *stack, int argc, char *argv[])
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (write(2, "Error\n", 6));
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (write(2, "Error\n", 6));
		if (!ft_check_for_duplicates(stack, (int)num, i - 1))
			return (write(2, "Error\n", 6));
		ft_adding_to_stack_a(stack, (int)num, i - 1);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**arguments;
	int		new_argc;

	if (argc < 2)
		return (write(2, "Error\n", 6));
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (!arguments)
			return (write(2, "Error\n", 6));
		new_argc = count_words(arguments);
		ft_allocate_sec(&stack, new_argc);
		if (new_numbers_sec(stack, new_argc, arguments) == 6)
			return (free_everything(arguments, stack));
		ft_free_split(arguments);
	}
	else
	{
		ft_allocate(&stack, argc);
		if (new_numbers(stack, argc, argv) == 6)
			return (ft_free(stack));
	}
	ft_algorithm(stack);
	return (ft_utils_main(stack));
}
