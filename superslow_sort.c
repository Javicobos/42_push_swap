/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superslow_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:28:43 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/18 13:50:51 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Find biggest element in a
Push everything else to b
Rotate b to put biggest in b on top
Push it to a
Repeat until b empty
*/

void superslow_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*cur_max;
	int			rotations_needed;

	cur_max = max_in_stack(stack_a);
	while (stack_a->total > 1)
	{
		if (stack_a->first == cur_max)
			rotate(stack_a);	//ra
		else
			push(stack_a, stack_b); //pb
	}
	while (stack_b->total > 0)
	{
		cur_max = max_in_stack(stack_b);
		rotations_needed = rotate_direction(stack_b, cur_max);
		if (rotations_needed > 0)
		{
			while (rotations_needed > 0)
			{
				rotate(stack_b); //rb
				rotations_needed--;
			}
		}
		else
		{
			while (rotations_needed < 1)
			{
				rev_rotate(stack_b);	//rrb
				rotations_needed++;
			}
		}
		if (stack_b->first != cur_max)
			ft_printf("Something went wrong \n");
		push(stack_b, stack_a);	//pa
	}
}