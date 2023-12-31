/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:47:58 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/17 12:01:00 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_doubles(t_stack *stack_a)
{
	t_stack	*aux1;
	t_stack	*aux2;
	long	nbr;

	aux1 = stack_a;
	while (aux1)
	{
		nbr = aux1->num;
		aux2 = aux1->next;
		while (aux2)
		{
			if (nbr == aux2->num)
			{
				ft_stack_clear(&stack_a);
				ft_error();
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

static long	ft_atol_strict(char **split, long i)
{
	long	result;
	int		j;
	int		sign;

	result = 0;
	j = 0;
	sign = check_sign(split, i, &j);
	while (split[i][j])
	{
		if (!ft_isdigit(split[i][j]))
		{
			ft_free_matrix(split);
			ft_error();
		}
		result = result * 10 + split[i][j++] - '0';
	}
	result = result * sign;
	check_fit_int(result, split);
	return (result);
}

static void	manage_strings(t_stack **stack_a, char **split)
{
	long	i;
	long	num;

	i = 0;
	while (split[i])
	{
		num = ft_atol_strict(split, i);
		fill_stack(stack_a, num);
		i++;
	}
}

void	ft_parse_args(char **argv, t_stack **stack_a)
{
	long	i;
	char	**split;
	long	num;

	i = 0;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		if (!split[1])
		{
			if (!split[0])
			{
				ft_free_matrix(split);
				ft_error();
			}
			num = ft_atol_strict(split, 0);
			fill_stack(stack_a, num);
		}
		else
			manage_strings(stack_a, split);
		ft_free_matrix(split);
	}
	check_doubles(*stack_a);
}
