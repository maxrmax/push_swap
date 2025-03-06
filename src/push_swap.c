/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/03/04 12:14:58 by mring            ###   ########.fr       */
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

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

//
//
//

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	partition_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	i = 0;
	pushed = 0;
	rotated = 0;
	pivot = (*stack_a)->value;
	while (i++ < size)
	{
		if ((*stack_a)->value < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
		{
			ra(stack_a);
			rotated++;
		}
	}
	while (rotated-- > 0)
		rra(stack_a); // Undo rotations
	return (pushed);  // Elements pushed to stack_b
}

void	quicksort_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	int left_size;  // left stack size
	int right_size; // right stack size
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	left_size = partition_push_swap(stack_a, stack_b, size);
	right_size = size - left_size; // size - left size
	if (left_size > 0)
		quicksort_push_swap(stack_a, stack_b, right_size);
	if (right_size > 0)
		quicksort_push_swap(stack_b, stack_a, left_size);
	while (*stack_b)
		pa(stack_a, stack_b); // Restore sorted values
}

//
//
//

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;
	int		size;

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
		size = stack_size(stack_a);
		quicksort_push_swap(&stack_a, &stack_b, size);
		print_stack(stack_a);
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