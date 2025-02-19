/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:05 by mring             #+#    #+#             */
/*   Updated: 2025/02/18 17:29:47 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **source, t_stack **destination)
//					stack b,				stack a
{
	t_stack *node;

	if (*source == NULL) //|| (*source)->next == NULL
		return ;
	node = *source; // first node saved locally
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node->next = *destination;       // point node at the old top of other stack
	if (*destination)                // but if dst is not NULL
		(*destination)->prev = node; // point prev back to new top
	node->prev = NULL;               // prev null bc top node
	*destination = node;             // move temp to the top of destination
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	// if (push(stack_b, stack_a))
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
