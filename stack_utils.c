/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:46:59 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/17 13:57:14 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack_a(t_number *first)
{
	t_number	*current;
	t_stack		*stack_a;
	int			total;

	stack_a = malloc(sizeof(*stack_a));
	if (!stack_a)
		return (0);
	stack_a->first = first;
	current = first;
	total = 1;
	while (current->next)
	{
		total++;
		current = current->next;
	}
	stack_a->total = total;
	stack_a->last = current;
	return (stack_a);
}

t_stack	*make_stack_b(void)
{
	t_stack		*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (!stack_b)
		return (0);
	stack_b->first = 0;
	stack_b->last = 0;
	stack_b->total = 0;
	return (stack_b);
}
