/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_p_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:17:19 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/17 13:58:47 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str);
int			is_valid_input(int argc, char **argv);
t_number	*make_numbers(int argc, char **argv);
int			good_numbers(t_number *first);

int	main(int argc, char **argv)
{
	t_number	*first;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1 || !is_valid_input(argc, argv))
		return (0);
	first = make_numbers(argc, argv);
	if (!first || !good_numbers(first))
		return (0);
	stack_a = make_stack_a(first);
	stack_b = make_stack_b();
}

long int	ft_atol(const char *str)
{
	int			neg_sign;
	long int	num_dec;

	num_dec = 0;
	neg_sign = 1;
	while (*str == ' ' || (8 < *str && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
		neg_sign = 44 - *(str++);
	while (('0' <= *str && *str <= '9'))
	{
		num_dec = num_dec * 10 + (*(str++) - '0');
		if (num_dec * neg_sign > INT_MAX || num_dec * neg_sign < INT_MIN)
			return (LONG_MAX);
	}
	if (*str == '\0')
		return (num_dec * neg_sign);
	return (LONG_MAX);
}

int	is_valid_input(int argc, char **argv)
{
	int	argument;

	argument = 1;
	while (argument < argc)
	{
		if ((ft_atol(argv[argument])) == LONG_MAX)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
	argument++;
	}
	return (1);
}

t_number	*make_numbers(int argc, char **argv)
{
	t_number	*first;
	t_number	*current;
	t_number	*previous;
	int			argument;

	first = malloc(sizeof(*first)); //create first outside and pass as param
	if (!first)
		return (0);
	argument = 1;
	current = first;
	previous = 0;
	while (argument < argc)
	{
		current->value = ft_atol(argv[argument]);
		current->prev = previous;
		if (++argument < argc)
		{
			current->next = malloc(sizeof(t_number));
			if (!current->next)
				return (0); //leaks?
			previous = current;
			current = current->next;
		}
	}
	current->next = 0;
	return (first);
}

int	good_numbers(t_number *first)
{
	t_number	*current;
	t_number	*checking;

	current = first;
	while (current)
	{
		checking = current->next;
		while (checking)
		{
			if (current->value == checking->value)
			{
			write(STDERR_FILENO, "Error\n", 6);
				return (0);
			}
			checking = checking->next;
		}
		current = current->next;
	}
	return (1);
}
