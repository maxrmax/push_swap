/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:28:24 by mring             #+#    #+#             */
/*   Updated: 2025/03/03 12:28:51 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplicates(t_stack **stack)
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

int	parsing(int ac, char **tokens, t_stack **stack_a)
{
	int	flag;

	flag = 0;
	if (int_range(tokens) == 1)
		flag = 1;
	if (create_stack(tokens, stack_a) == 1)
		flag = 1;
	if (check_duplicates(stack_a) == 1)
		flag = 1;
	if (ac == 2)
		free_tokens(tokens);
	if (flag == 1)
		return (1);
	return (0);
}
