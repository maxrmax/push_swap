/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:29:03 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 14:52:31 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_desc(t_stack **stack_b)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
		rb(stack_b);
	else
		return ;
}

void	sort_two(t_stack **stack_a)
{
	sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > third && third > second)
		ra(stack_a);
	else if (second > first && second > third && first > third)
		rra(stack_a);
	else if (first > second && first < third)
		sa(stack_a);
	else if (first < third && second > third)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	smallest = find_smallest(*stack_a);
	while (*stack_a != smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	smallest = find_smallest(*stack_a);
	while (*stack_a != smallest)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
