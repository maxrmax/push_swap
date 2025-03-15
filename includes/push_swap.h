/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:03:20 by mring             #+#    #+#             */
/*   Updated: 2025/03/15 09:53:24 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
// # include <stdlib.h> included in libft.h
// # include <unistd.h> included in libft.h
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// operations
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// parsing
int					parsing(int ac, char **tokens, t_stack **stack_a);
bool				check_duplicates(t_stack **stack);
bool				int_range(char **tokens);

// sorting functions
int					stack_size(t_stack *stack);
bool				is_sorted(t_stack *stack);
void				sort_two_desc(t_stack **stack_b);
void				sort_two(t_stack **stack_a);
void				sort_three(t_stack **stack_a);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_smallest(t_stack *stack);
void				sort_five(t_stack **stack_a, t_stack **stack_b);

// main sort
void				ksort(t_stack **stack_a, t_stack **stack_b);
void				index_stack(t_stack **stack);
void				push_b(t_stack **stack_a, t_stack **stack_b);
int					ft_sqrt(int n);
void				push_back(t_stack **stack_a, t_stack **stack_b);
int					get_moves(t_stack *stack_b);

// node, stack creation and freeing
bool				create_stack(char **tokens, t_stack **stack_a);
t_stack				*create_node(int n);
void				free_stack(t_stack *stack_a);
void				free_tokens(char **tokens);
long				ft_atol(const char *str);

#endif