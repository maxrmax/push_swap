/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:48:56 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 16:15:54 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_in_stack(t_stack **stack_one, t_stack **stack_two)
{
	int		difference;
	t_stack	*current_one;
	t_stack	*current_two;

	current_one = *stack_one;
	while (current_one)
	{
		difference = INT_MAX;
		current_two = *stack_two;
		while (current_two)
		{
			if (current_one->value > current_two->value)
			{
				if (current_one->value - current_two->value < difference)
				{
					difference = current_one->value - current_two->value;
					current_one->target = current_two;
				}
			}
			current_two = current_two->next;
		}
		if (difference == INT_MAX)
			current_one->target = highest_number(stack_two);
		current_one = current_one->next;
	}
}

void	calc_push_cost(t_stack **stack_a, t_stack **stack_b)
{
	int	cost_a;
	int	cost_b;

	while (*stack_a)
	{
		cost_a = 0;
		cost_b = 0;
		if ((*stack_a)->above_median)
			cost_a = (*stack_a)->index;
		else if (!((*stack_a)->above_median))
			cost_a = (stack_size(*stack_a) - (*stack_a)->index);
		if ((*stack_a)->target->above_median)
			cost_b = (*stack_a)->target->index;
		else if (!((*stack_a)->target->above_median))
			cost_b = (stack_size(*stack_b) - (*stack_a)->index);
		if ((*stack_a)->above_median == (*stack_a)->target->above_median)
			if (cost_a > cost_b)
				(*stack_a)->push_cost = cost_a;
			else
				(*stack_a)->push_cost = cost_b;
		else
			(*stack_a)->push_cost = cost_a + cost_b;
		(*stack_a) = (*stack_a)->next;
	}
}
