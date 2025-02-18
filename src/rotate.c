/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:10 by mring             #+#    #+#             */
/*   Updated: 2025/02/18 10:59:57 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;     // Store top of the node
	tail = *stack;     // tail to find last node
	while (tail->next) // find last node
		tail = tail->next;
	*stack = head->next; // new top is second element
	head->next = NULL;   // old top is now last element
	(*stack)->prev = NULL;
	tail->next = head; // link old top to the end
	head->prev = tail;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
