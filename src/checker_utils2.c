/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:19:00 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 17:28:26 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra_c(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb_c(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr_c(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
