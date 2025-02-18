/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/02/18 16:19:24 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// double link list
// alle funktionieren die ich hab in der link list rein
// struktur um beide stacks reinzupacken
// alle vom subjekt verlangte funktionieren mit pointer auf der struktur der stacks
// debug funktioert der die stacks ausprintet
// ^^^^ basis
// jetzt sortier algorithmus
// ----
// tipp from tillie: start with bubble sort
//	- have elements that point to the original element
// sort it in an extra stack and overwrite the original numbers

// Program name push_swap
// Turn in files Makefile, *.h, *.c
// Makefile NAME, all, clean, fclean, re
// Arguments stack a: A list of integers
// External functs.
// • read, write, malloc, free,
// exit
// • ft_printf and any equivalent
// YOU coded
// Libft authorized Yes
// Description Sort stacks

// Allowed functions:
// read, write, malloc, free, exit
// anything i coded.

/*
input parsing, sub function or in main?
how to parse? should only be numbers
*/

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Utility function to print the stack
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
	while (temp != NULL && temp->next)
		temp = temp->next;
	while (temp != NULL && i >= 0)
	{
		printf("%d ", temp->value);
		temp = temp->prev;
		i--;
	}
	printf("\n");
}

// Utility function to create a new node
t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node)
	{
		node->value = value;
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*node2;
	t_stack	*node3;
	t_stack	*node4;
	t_stack	*node5;
	t_stack	*stack_b;

	// Initialize stack A: 6 -> 7 -> 2 -> 3 -> 1
	stack_a = new_node(6);
	node2 = new_node(7);
	node3 = new_node(2);
	node4 = new_node(3);
	node5 = new_node(1);
	stack_a->next = node2;
	node2->prev = stack_a;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	node4->next = node5;
	node5->prev = node4;
	stack_b = NULL;
	// Print the original stack
	printf("Original Stack A: \n");
	print_stack(stack_a);
	// Test pa (push from A to B)
	pb(&stack_a, &stack_b); // push top of a to top of b
	pb(&stack_a, &stack_b); // push top of a to top of b
	pb(&stack_a, &stack_b); // push top of a to top of b
	rr(&stack_a, &stack_b); // 3 1 - 2 7 6
	// Stack A should become 7 2 3 1 and Stack B should be 6
	printf("After pb (push to stack B): Stack A: \n");
	print_stack(stack_a);
	printf("Stack B: ");
	print_stack(stack_b);
	printf("After pa (push to stack A): Stack A:\n");
	pa(&stack_a, &stack_b); // push top of b to top of a
	print_stack(stack_a);
	printf("Stack B: ");
	print_stack(stack_b);
	// Test swap (sa)
	// sa(&stack_a);
	// Stack A should become 2 7 3 1 and Stack B should remain 6
	// printf("After sa (swap stack A): Stack A: \n");
	// print_stack(stack_a);
	// Test rotate (ra)
	// ra(&stack_a); // Stack A should become 2 3 1 6
	// printf("After ra (rotate stack A): Stack A: \n");
	// print_stack(stack_a);
	// Test reverse rotate (rra)
	// rra(&stack_a); // Stack A should become 6 2 3 1
	// printf("After rra (reverse rotate stack A): Stack A: \n");
	// print_stack(stack_a);
	// Free allocated memory
	free(stack_a);
	// free(node2);
	// free(node3);
	// free(node4);
	// free(node5);
	free(stack_b);
	return (0);
}

// #include "push_swap.h"

// // first argument is the top of the stack ./push_swap 1 9 6 5 2 3
// // need to handle string input too "1 2 3 4 5 6 7 9 8" > atoi
// int	main(int ac, char **av)
// {
// 	if (ac == 1 || (ac >= 2 && !av[1][0]))
// 		return (1);
// 	if (ac == 2)
// 	{
// 		// split logic
// 	}
// 	else
// 	{
// 		// skip split logic
// 	}
// 	// atoi necesarry for both. "1 2 3 4 5" < needs split ./a.out 1 2 3 4 5 < doesn't need split
// }

/*
V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a.
To do so you have the following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.

-------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
-------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
-------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
-------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
-------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
-------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
-------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
------------------- */