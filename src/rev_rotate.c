/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:08 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 17:51:52 by mring            ###   ########.fr       */
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

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
