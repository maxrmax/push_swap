/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/02/24 18:11:08 by mring            ###   ########.fr       */
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

	// returns a char **argv as int
	// argv[0] = "132", [1] = "2", [2] = "333"
	if (ac == 2)
		elements = ft_split(av[1], ' ');
	else
		elements = av + 1; // element[0] == av[1]
	i = 0;
	while (elements[i])
	{
		new_node = create_node(ft_atoi(elements[i]));
		if (!new_node)
			return ;
		if (!*stack_a) // stack inititalizaiton
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
void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	/*
	okay, how do i approach this?
	i have my unsorted stack (a).
	I have to use stack_b to sort from a to b, with b, on b, to a.
	Now i have to think about the rules and confinement of my function to sort use the operations.
	lets say i have this stack: 6 7 5 3 9 1 2 0 4 8
	1. i thought about using a hash set to have all appearing numbers put into it and then print them in asc order
	the lowest would be the first to be encountered after all ------
	-----
	2. i could also check the first two numbers- push the lowest or highest to b,
	check the first two for h/l again, compare against b, and add accordingly
		- i guess that is insertion sort?
	Time Complexity Focus:
	QuickSort (O(n log n)): Can be implemented with a pivot and partitioning strategy using your two stacks.
	MergeSort (O(n log n)): Involves recursive merging and might require creative management of your stacks to merge in place.
	TurkSort (O(n log n)): A hybrid of insertion sort for small subarrays and QuickSort for larger subarrays could complement your two-stack strategy.
	*/
}

// check for duplicates (how?)
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || !av[1][0])
		return (1);
	create_stack(ac, av, &stack_a);
	print_stack(stack_a);
	bubble_sort(&stack_a, &stack_b);
	print_stack(stack_a);
	// cleanup
}

/*
	Run push_swap with non numeric parameters. The program must
	display "Error".

	Run push_swap with a duplicate numeric parameter. The program
	must display "Error".

	Run push_swap with only numeric parameters including one greater
	than MAXINT. The program must display "Error".

	Run push_swap without any parameters. The program must not
	display anything and give the prompt back.


	Run the following command "$>./push_swap 42". The program
	should display nothing (0 instruction).

	Run the following command "$>./push_swap 2 3". The
	program should display nothing (0 instruction).

	Run the following command "$>./push_swap 0 1 2 3". The
	program should display nothing (0 instruction).

	Run the following command "$>./push_swap 0 1 2 3 4 5 6 7 8
	9". The program should display nothing (0 instruction).

	Run the following command "$>./push_swap 'Between 0 and 9 randomly
	sorted values chosen>'. The program should display nothing
	(0 instruction).


	Run "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG".
	Check that the checker program displays "OK" and that the
	size of the list of instructions from push_swap is 2 OR 3.
	Otherwise the test fails.

	Run "$>ARG="'Between 0 and 3 randomly values chosen'"; ./push_swap
	$ARG | ./checker_OS $ARG". Check that the checker program displays
	"OK" and that the size of the list of instructions from push_swap
	is between 0 AND 3. Otherwise the test fails.


	Run "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG".
	Check that the checker program displays "OK" and that the
	size of the list of instructions from push_swap isn't more
	than 12. Kudos if the size of the list of instructions is 8.

	Run "$>ARG="<5 random values>"; ./push_swap $ARG | ./checker_OS
	$ARG" and replace the placeholder by 5 random valid values.
	Check that the checker program displays "OK" and that the
	size of the list of instructions from push_swap isn't more
	than 12. Otherwise this test fails. You'll have to
	specifically check that the program wasn't developed to only
	answer correctly on the test included in this scale. You
	should repeat this test couple of times with several
	permutations before you validate it.


Run "$>ARG="<100 random values>"; ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 100 random valid values. Check that the checker program displays "OK" and that the size of the list of instructions. Give points in accordance:

	less than 700: 5
	less than 900: 4
	less than 1100: 3
	less than 1300: 2
	less than 1500: 1 You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it.


	Run "$>ARG="<500 random values>"; ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 500 random valid values (One is not called John/Jane Script for nothing). Check that the checker program displays "OK" and that the size of the list of instructions
		less than 5500: 5
		less than 7000: 4
		less than 8500: 3
		less than 10000: 2
		less than 11500: 1 You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it.

*/

/*
Checker program - Error management

In this section, we'll evaluate the checker's error management.
If at least one fails, no points will be awarded for this
section. Move to the next one.

	Run checker with non numeric parameters. The program must
	display "Error".

	Run checker with a duplicate numeric parameter. The program
	must display "Error".

	Run checker with only numeric parameters including one greater
	than MAXINT. The program must display "Error".

	Run checker without any parameters. The program must not
	display anything and give the prompt back.

	Run checker with valid parameters, and write an action that
	doesn't exist during the instruction phase. The program must
	display "Error".

	Run checker with valid parameters, and write an action with
	one or several spaces before and/or after the action during
	the instruction phase. The program must display "Error".

Checker program - False tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that doesn't sort the list. Execute the
following 2 tests. If at least one fails, no points will be
awarded for this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
intruction phase.

	Run checker with the following command "$>./checker 0 9 1 8 2
	7 3 6 4 5" then write the following valid action list "[sa,
	pb, rrr]". Checker should display "KO".

	Run checker with a valid list as parameter of your choice then
	write a valid instruction list that doesn't order the
	integers. Checker should display "KO". You'll have to
	specifically check that the program wasn't developed to only
	answer correctly on the test included in this scale. You
	should repeat this test couple of times with several
	permutations before you validate it.

Checker program - Right tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that sort the list. Execute the following
2 tests. If at least one fails, no points will be awarded for
this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
instruction phase.

	Run checker with the following command "$>./checker 0 1 2"
	then press CTRL+D without writing any instruction. The program
	should display "OK".

	Run checker with the following command "$>./checker 0 9 1 8 2"
	then write the following valid action list "[pb, ra, pb, ra,
	sa, ra, pa, pa]". The program should display "OK".

	Run checker with a valid list as parameter of your choice then
	write a valid instruction list that order the integers.
	Checker must display "OK". You'll have to specifically check
	that the program wasn't developed to only answer correctly on
	the test included in this scale. You should repeat this test
	couple of times with several permutations before you validate
	it.

*/