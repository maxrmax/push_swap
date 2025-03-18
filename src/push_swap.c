/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 18:04:39 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_start(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 5)
	{
		if (size == 2)
			sort_two(stack_a);
		if (size == 3)
			sort_three(stack_a);
		if (size == 4)
			sort_four(stack_a, stack_b);
		if (size == 5)
			sort_five(stack_a, stack_b);
		return ;
	}
	else
		ksort(stack_a, stack_b);
}

void	ksort(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(stack_a);
	push_b(stack_a, stack_b);
	push_back(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !av[1][0])
		return (0);
	if (ac == 2)
		tokens = ft_split(av[1], ' ');
	else
		tokens = av + 1;
	if (parsing(ac, tokens, &stack_a) == 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (free_stack(stack_a), 1);
	}
	else
		sorting_start(&stack_a, &stack_b);
	return (free_stack(stack_a), 0);
}
