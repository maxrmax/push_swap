/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:02 by mring             #+#    #+#             */
/*   Updated: 2025/03/13 17:33:53 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	return (node);
}

bool	create_stack(char **tokens, t_stack **stack_a)
{
	t_stack	*new_node;
	t_stack	*current;
	long	n;
	int		i;

	i = -1;
	while (tokens[++i])
	{
		n = ft_atol(tokens[i]);
		if (n < INT_MIN)
			return (1);
		new_node = create_node(n);
		if (!new_node)
			return (1);
		if (!*stack_a)
			*stack_a = new_node;
		else
			current->next = new_node;
		current = new_node;
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

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}
