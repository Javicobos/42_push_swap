/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:46:59 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/18 15:29:46 by jcobos-d         ###   ########.fr       */
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

void	stack_printer(t_stack *to_print)
{
	t_number	*cur;

	ft_printf("----- STACK DATA -----\n");
	ft_printf("my stack is at %p.\n", to_print);
	ft_printf("the first element is at %p.\n", to_print->first);
	ft_printf("the last element is at %p.\n", to_print->last);
	ft_printf("the total number of elements is %i.\n", to_print->total);
	cur = to_print->first;
	while (cur)
	{
		ft_printf("----- element data -----\n");
		ft_printf("the number %i is at %p.\n", cur->value, cur);
		ft_printf("prev element is %p, next is %p.\n", cur->prev, cur->next);
		cur = cur->next;
	}
}
