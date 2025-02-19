/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/02/19 17:06:30 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tipp from tillie: start with bubble sort

// External functs.
// • read, write, malloc, free, exit
// • libft, ft_printf, get_next_line, anything i coded.

// You have to turn in a Makefile which will compile your source files. It must not
// relink.

// Global variables are forbidden.

// You have to write a program named push_swap that takes as an argument the stack
// a formatted as a list of integers. The first argument should be at the top of the
// stack (be careful about the order).

// The program must display the smallest list of instructions possible to sort the stack
// a, the smallest number being at the top.

// Instructions must be separated by a ’\n’ and nothing else.

// The goal is to sort the stack with the lowest possible number of operations. During
// the evaluation process,
// the number of instructions found by your program will be
// compared against a limit: the maximum number of operations tolerated. If your
// program either displays a longer list or if the numbers aren’t sorted properly,
// your
// grade will be 0.

// If no parameters are specified,
// the program must not display anything and give the
// prompt back.

// In case of error,
// it must display "Error" followed by a ’\n’ on the standard error.
// Errors include for example: some arguments aren’t integers,
// some arguments are
// bigger than an integer and/or there are duplicates.

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

void	create_stack(int ac, char **av, t_stack **stack_a)
{
	t_stack	*new_node;
	t_stack	*current;
	char	**elements;
	int		i;

	i = 0;
	// returns a char **argv -> argv[0] = "1",
	// [1] = "2", [2] = "333"
	if (ac == 2)
		elements = ft_split(av[1], ' ');
	else
		elements = av + 1; // element[0] == av[1]
	while (elements[i])
	{
		new_node = create_node(ft_atoi(elements[i]));
		if (!new_node)
			return ;
		if (!*stack_a)
		{
			*stack_a = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			new_node->next = current;
			current = new_node;
		}
		i++;
	}
	print_stack(*stack_a);
	return ;
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp != NULL && i <= 10)
	{
		printf("%d ", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
	temp = stack;
	i = 0;
	while (temp != NULL && temp->next && i <= 10)
	{
		temp = temp->next;
		i++;
	}
	while (temp != NULL && i >= 0)
	{
		printf("%d ", temp->value);
		temp = temp->prev;
		i--;
	}
	printf("\n");
}

// split if ac == 2
// converting them into int
// assign to node, ac 1 == node 0
// link nodes
//
//
//
// check ac amount, ac == 2 needs split
// malloc times of arguments (amount of nodes)
// atoi argument and assign value to node
// check for duplicates (how?)
// ./a.out "1 2 3 4 5" < ac == 2 needs split
// ./a.out 1 2 3 4 5 < 				doesn't need split
//
// first argument is the top of the stack ./push_swap 1 9 6 5 2 3
// need to handle string input too "1 2 3 4 5 6 7 9 8" > atoi
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac >= 2 && !av[1][0]))
		return (1);
	create_stack(ac, av, &stack_a);
	// call algorithm
	// cleanup
}
