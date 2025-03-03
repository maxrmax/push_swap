/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/03/03 11:15:31 by mring            ###   ########.fr       */
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

//
//
//

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (str[i])
		return (LONG_MIN);
	return (result * sign);
}

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

int	create_stack(char **tokens, t_stack **stack_a)
{
	t_stack	*new_node;
	t_stack	*current;
	long	n;
	int		i;

	i = 0;
	while (tokens[i])
	{
		n = ft_atol(tokens[i]);
		printf("n: %ld\n", n);
		if (n < INT_MIN)
			return (1);
		new_node = create_node(n);
		if (!new_node)
			return (1);
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
	return (0);
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

int	check_duplicates(t_stack **stack)
{
	t_stack	*current;
	t_stack	*check;

	current = *stack;
	while (current->next)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

bool	int_range(char **tokens)
{
	char	max[11] = "2147483647";
	char	min[12] = "-2147483648";
	int		i;
	int		len;

	i = 0;
	while (tokens[i])
	{
		len = ft_strlen(tokens[i]);
		if (len > 10 && tokens[i][0] != '-')
			return (1);
		if (len == 10 || (len == 11 && tokens[i][0] == '-'))
		{
			if (tokens[i][0] == '-' && (ft_strncmp(tokens[i], min, 11) > 0))
				return (1);
			else if (ft_strncmp(tokens[i], max, 10) > 0)
				return (1);
		}
		i++;
	}
	return (0);
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

int	parse(int ac, char **av, t_stack **stack_a)
{
	char	**tokens;
	int		check;
	int		i;

	if (ac == 2)
		tokens = ft_split(av[1], ' ');
	else
		tokens = av + 1;
	if (int_range(tokens) == 1)
		return (1);
	check = create_stack(tokens, stack_a);
	if (check_duplicates(stack_a) == 1 || check == 1)
		return (1);
	print_stack(*stack_a);
	if (ac == 2) // freeing if split was used
	{
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !av[1][0])
		return (0);
	if (parse(ac, av, &stack_a) == 1)
	{
		// if (!stack_a)
		// 	free_stack(stack_a);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	bubble_sort(&stack_a, &stack_b);
	// sorting_method(&stack_a, &stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
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