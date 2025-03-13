/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:56:38 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 20:33:55 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ksort(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(stack_a);
	push_b(stack_a, stack_b);
	push_back(stack_a, stack_b);
}

void	index_stack(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack_a;
	while (current)
	{
		compare = *stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		index = 0;
		current = current->next;
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		count;
	int		range;

	count = 0;
	range = ft_sqrt(stack_size(*stack_a)) * 1.6;
	while (*stack_a)
	{
		current = *stack_a;
		if ((*stack_a)->index <= count)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			count++;
		}
		else if ((*stack_a)->index < count + range)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
		{
			ra(stack_a);
		}
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	moves;

	while (*stack_b)
	{
		moves = get_moves(*stack_b);
		if (moves > 0)
		{
			while (moves-- > 0)
				rb(stack_b);
		}
		else
		{
			moves = -moves;
			while (moves-- > 0)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

int	get_moves(t_stack *stack_b)
{
	t_stack	*temp;

	int max_index, count, max_value, forward_moves, reverse_moves;
	if (!stack_b)
		return (0);
	max_value = stack_b->value;
	max_index = count = 0;
	temp = stack_b;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_index = count;
		}
		count++;
		temp = temp->next;
	}
	forward_moves = max_index;
	reverse_moves = stack_size(stack_b) - max_index;
	if (forward_moves <= reverse_moves)
		return (forward_moves);
	else
		return (-reverse_moves);
}
