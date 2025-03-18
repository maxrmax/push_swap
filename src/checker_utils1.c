/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:19:00 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 17:28:09 by mring            ###   ########.fr       */
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
	node->next = *destination;
	*destination = node;
}

void	pa_c(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	pb_c(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}