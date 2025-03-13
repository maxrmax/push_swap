/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:56:38 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 16:17:05 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turksort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapestnode;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_two_desc(stack_b);
	while (stack_size(*stack_a) > 3)
	{
		index_median(stack_a);
		index_median(stack_b);
		target_in_stack(stack_a, stack_b);
		cheapestnode = find_cheapest(stack_a);
	}
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
	{
		index_median(stack_a);
		index_median(stack_b);
		target_in_stack(stack_b, stack_a);
	}
}
