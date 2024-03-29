/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:16 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/18 15:31:30 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_number
{
	int				value;
	struct s_number	*next;
	struct s_number	*prev;
}	t_number;

typedef struct s_stack
{
	t_number		*first;
	t_number		*last;
	int				total;
}	t_stack;

void		swap(t_stack *stack);
void		push(t_stack *src, t_stack *dest);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);

t_stack		*make_stack_a(t_number *first);
t_stack		*make_stack_b(void);
void		stack_printer(t_stack *to_print);

int			is_sorted(t_stack *stack);
t_number	*max_in_stack(t_stack *stack);
t_number	*min_in_stack(t_stack *stack);
int			rotate_direction(t_stack *stack, t_number *ele);

void		superslow_sort(t_stack *stack_a, t_stack *stack_b);

#endif