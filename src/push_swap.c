/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/02/26 10:48:09 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack);

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	create_stack(char **tokens, t_stack **stack_a)
{
	t_stack	*new_node;
	t_stack	*current;
	int		i;

	i = 0;
	while (tokens[i])
	{
		new_node = create_node(ft_atoi(tokens[i]));
		if (!new_node)
			break ;
		if (!*stack_a)
		{
			*stack_a = new_node; // add first node to stack
			current = new_node;
		}
		else // adding all other nodes
		{
			current->next = new_node; // add new_node to next pos
			new_node->prev = current; // prev from new_node to current
			current = new_node;       // new_node is now current node
		}
		i++;
	}
	return ;
}

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

void	bubble_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	(void)stack_b;
	int i, j;
	n = stack_size(*stack_a);
	i = 0;
	while (i < n - 1)
	{
		/* Each pass, do (n - 1 - i) comparisons and rotations */
		j = 0;
		while (j < n - 1 - i)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
			ra(stack_a);
			j++;
		}
		/* Undo the rotations performed in this pass */
		while (j-- > 0)
			rra(stack_a);
		i++;
	}
}

void	free_stack(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

bool	parsing(char **tokens)
{
	char	max[11] = "2147483647";
	char	min[11] = "2147483648";
	int		i;
	int		len;

	i = 0;
	while (tokens[i])
	{
		len = ft_strlen(tokens[i]);
		if (len > 10 && tokens[i][0] != '-')
			return (1);
		if (len == 10 || (len == 11 && tokens[i][0] == '-'))
			if (tokens[i][0] == '-' && (ft_strncmp(tokens[i], min, 10) > 0))
				return (1);
			else if (ft_strncmp(tokens[i], max, 10) > 0)
				return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || !av[1][0])
		return (1);
	if (ac == 2)
		tokens = ft_split(av[1], ' ');
	else
		tokens = av + 1;
	if (parsing(tokens) == 0)
	{
		create_stack(tokens, &stack_a);
		// print_stack(stack_a);
		bubble_sort(&stack_a, &stack_b);
		// print_stack(stack_a);
	}
	free_stack(stack_a);
	if (ac == 2) // freeing if split was used
	{
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
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