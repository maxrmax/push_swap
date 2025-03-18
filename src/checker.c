/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:05 by mring             #+#    #+#             */
/*   Updated: 2025/03/18 18:03:35 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;

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
	read_commands(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free_stack(stack_a), 0);
}

void	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = NULL;
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			return ;
		exec_commands(command, stack_a, stack_b);
		free(command);
	}
}

void	exec_commands(char *command, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(command, "pb\n", 4) == 0)
		pb_c(stack_a, stack_b);
	else if (ft_strncmp(command, "pa\n", 4) == 0)
		pa_c(stack_a, stack_b);
	else if (ft_strncmp(command, "ra\n", 4) == 0)
		ra_c(stack_a);
	else if (ft_strncmp(command, "rb\n", 4) == 0)
		rb_c(stack_b);
	else if (ft_strncmp(command, "sa\n", 4) == 0)
		sa_c(stack_a);
	else if (ft_strncmp(command, "sb\n", 4) == 0)
		sb_c(stack_b);
	else if (ft_strncmp(command, "ss\n", 4) == 0)
		ss_c(stack_a, stack_b);
	else if (ft_strncmp(command, "rra\n", 5) == 0)
		rra_c(stack_a);
	else if (ft_strncmp(command, "rrb\n", 5) == 0)
		rrb_c(stack_b);
	else if (ft_strncmp(command, "rrr\n", 5) == 0)
		rrr_c(stack_a, stack_b);
	else if (ft_strncmp(command, "rr\n", 4) == 0)
		rr_c(stack_a, stack_b);
	else
		exit(ft_printf("Error\n"));
}
