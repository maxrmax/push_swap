/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:03:20 by mring             #+#    #+#             */
/*   Updated: 2025/01/22 11:58:42 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void				sa(void);
void				sb(void);
void				ss(void);
void				ra(void);
void				rb(void);
void				rr(void);
void				rra(void);
void				rrb(void);
void				rrr(void);
void				pa(void);
void				pb(void);

#endif