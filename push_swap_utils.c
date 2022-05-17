/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:13 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/17 11:13:19 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
sa(swap a) : Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
#include "push_swap.h"

void swap(t_stack *stack)
{
	t_number	*f_to_s;
	t_number	*s_to_f;

	if (stack->total < 2)
		return ;
	f_to_s = stack->first;
	s_to_f = stack->first->next;
	f_to_s->next = s_to_f->next;
	f_to_s->prev = s_to_f;
	s_to_f->next = f_to_s;
	s_to_f->prev = 0;
	stack->first = s_to_f;
}
/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
void push(t_stack *src, t_stack *dest)
{
	t_number	*pushing;

	if (!(src->first))
		return;
	if (src->first->next)
		src->first->next->prev = 0;
	else
		src->last = 0;
	pushing = src->first;
	src->first = src->first->next;
	if (dest->first)
		dest->first->prev = pushing;
	else
		dest->last = pushing;
	pushing->next = dest->first;
	dest->first = pushing;
	src->total--;
	dest->total++;
}

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void rotate(t_stack* stack)
{
	if (stack->total < 2)
		return;
	stack->first->prev = stack->last;
	stack->last->next = stack->first;
	stack->last = stack->first;
	stack->first = stack->last->next;
	stack->first->prev = 0;
	stack->last->next = 0;
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void rev_rotate(t_stack* stack)
{
	if (stack->total < 2)
		return;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->first = stack->last;
	stack->last = stack->first->prev;
	stack->last->next = 0;
	stack->first->prev = 0;
}