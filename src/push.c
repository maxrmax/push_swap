/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:05 by mring             #+#    #+#             */
/*   Updated: 2025/03/10 17:23:14 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **source, t_stack **destination)
{
	t_stack	*node;

	if (*source == NULL)
		return ;
	node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node->next = *destination;
	if (*destination)
		(*destination)->prev = node;
	node->prev = NULL;
	*destination = node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
