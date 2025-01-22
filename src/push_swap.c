/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:31:50 by mring             #+#    #+#             */
/*   Updated: 2025/01/22 13:47:37 by mring            ###   ########.fr       */
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

// first argument is the top of the stack ./push_swap 1 9 6 5 2 3
int	main(int ac, char **argv)
{
	if (ac == 1 || (ac == 2 && !argv[1][0]))
		return (1);
	else if (ac == 2)
		write(1, "\n", 1);
}

/*
V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
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