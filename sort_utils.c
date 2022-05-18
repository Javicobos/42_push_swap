/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:34:39 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/18 15:07:13 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_number	*current;
	int			minval;

	current = stack->first;
	minval = current->value;
	while (current->next)
	{
		if (minval > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_number	*max_in_stack(t_stack *stack)
{
	t_number	*current;
	t_number	*max;

	current = stack->first;
	max = current;
	while (current->next)
	{
		if (max->value < current->next->value)
			max = current ->next;
		current = current->next;
	}
	return (max);
}

t_number	*min_in_stack(t_stack *stack)
{
	t_number	*current;
	t_number	*min;

	current = stack->first;
	min = current;
	while (current->next)
	{
		if (min->value < current->next->value)
			min = current->next;
		current = current->next;
	}
	return (min);
}

int	rotate_direction(t_stack *stack, t_number *ele)
{
	t_number	*current;
	int			elements_before;
	int			elements_after;

	current = ele;
	elements_before = 0;
	while (current->prev)
	{
		elements_before++;
		current = current->prev;
	}
	elements_after = stack->total - elements_before - 1;
	if (elements_before < elements_after)
		return (elements_before);
	return (-elements_after - 1);
}
