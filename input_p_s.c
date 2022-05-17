/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_p_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:17:19 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/05/17 12:39:08 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str);
int	is_valid_input(int argc, char **argv);

int main(int argc, char **argv)
{

	if (argc == 1)
		return (0);
	if (!is_valid_input(argc, argv))
		return (0);
	
}

long int	ft_atol(const char *str)
{
	int					neg_sign;
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
			ft_printf("Error \n");
			return (0);
		}
	argument++;
	}
	return (1);
}