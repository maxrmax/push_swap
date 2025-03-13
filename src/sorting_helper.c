/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:01:16 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 17:21:35 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*highest_number(t_stack **stack)
{
	t_stack	*highest_number;
	t_stack	*current;

	current = *stack;
	highest_number = *stack;
	while (current)
	{
		if (highest_number->value < current->value)
			highest_number = current;
		else
			current = current->next;
	}
	return (highest_number);
}

t_stack	*find_cheapest(t_stack)
{
}