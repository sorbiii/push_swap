/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:53 by nadamczy          #+#    #+#             */
/*   Updated: 2025/05/22 11:51:40 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct Stack_s
{
	int		*stack_a;
	int		*stack_b;
	size_t	size_a;
	size_t	size_b;
	int		*cheap_array;
	int		num_ra;
	int		num_rb;
	int		num_rra;
	int		num_rrb;
	int		num_rr;
	int		num_rrr;
	int		num_of_moves;
}	t_stack;

void	ft_adding_to_stack_a(t_stack *stack, int num, int index);
void	ft_adding_to_stack_b(t_stack *stack, int num, int index);
int		ft_free(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	ft_algorithm(t_stack *stack);
void	ft_compute_moves_for_all(t_stack *stack);
int		find_position_in_b_desc(int *stack_b, int size_b, int value);
int		rotation_cost(int size, int value);
void	ft_compute_moves_for_a(t_stack *stack);
int		ft_utils_for_computing(int cost_a, int cost_b, int total);
int		find_position_a_for_b(t_stack *stack, int value);
int		ft_sub_absolut_value(int a, int b);
void	ft_sort_three_elem(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_turk_start(t_stack *stack);
void	ft_make_operations_utils(t_stack *stack);
void	ft_make_operations(t_stack *stack);
void	ft_less(t_stack *stack);
void	ft_num_of_operations(t_stack *stack, int pos_b, int pos_a);
void	ft_num_of_operations_a(t_stack *stack, int pos_a);
void	ft_reset(t_stack *stack);
void	ft_turk(t_stack *stack);
void	ft_turk_for_a(t_stack *stack);
void	ft_small_a_to_top(t_stack *stack);
void	ft_push_to_a(t_stack *stack);
int		find_min_index(int *stack, size_t size);
void	ft_sort_four_elem(t_stack *stack);
void	find_max(const int *stack_b, int size_b, int *max, int *max_index);
int		first_check(t_stack *stack);
void	ft_last_from_a(t_stack *stack);
int		small_candidate(t_stack *stack, int candidate, int candidate_index);
int		ft_utils_main(t_stack *stack);
int		new_numbers_sec(t_stack *stack, int argc, char *argv[]);
void	ft_allocate_sec(t_stack **stack, int argc);
int		count_words(char **str);
void	ft_free_split(char **arr);
int		ft_check_for_duplicates(t_stack *stack, int num, int index);
int		free_everything(char **arguments, t_stack *stack);
void	ft_sort_five_elem(t_stack *s);
void	ft_push_min_to_b(t_stack *stack);
long	ft_atol(const char *str);
int		is_valid_number(const char *str);
#endif
