/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:19:00 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 17:28:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last = *stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	tail = second_last->next;
	second_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra_c(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb_c(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr_c(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
