/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 15:39:00 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	while (temp != NULL && temp->next)
	{
		temp = temp->next;
	}
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->prev;
	}
	printf("\n");
}

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
		turksort(stack_a, stack_b);
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
	{
		sorting_start(&stack_a, &stack_b);
		printf("a: ");
		print_stack(stack_a);
		printf("b: ");
		print_stack(stack_b);
	}
	return (free_stack(stack_a), 0);
}

/*
sa 	-> swap a[0] and a[1]
sb 	-> swap b[0] and b[1]
ss 	-> swap both
pa 	-> from b[0] to a[0]
pb 	-> from a[0] to b[0]
ra 	-> shift everything of a up by 1 (first to last)
rb 	-> shift everything of b up by 1 (first to last)
rr 	-> shift both by 1
rra	-> shift everything of a down by 1 (last to first)
rrb	-> shift everything of b down by 1 (last to first)
rrr	-> shift both down by 1
*/

/*
INT_MIN: -2147483648
	Bit: 10000000 00000000 00000000 00000000
	Hex: 0x80000000
INT_MAX: 2147483647
	Bit: 01111111 11111111 11111111 11111111
	Hex: 0x7FFFFFFF
*/