/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:16 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/17 12:34:04 by jcobos-d         ###   ########.fr       */
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
	int	value;
	struct s_number *next;
	struct s_number *prev;
} t_number;

typedef struct s_stack
{
	t_number *first;
	t_number *last;
	int		total;
}	t_stack;

#endif