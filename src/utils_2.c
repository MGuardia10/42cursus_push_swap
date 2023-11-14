/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:31 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/14 10:52:37 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		ft_printf("%d\n", aux->num);
		aux = aux->next;
	}
}

int	get_index(t_stack *stack, long min)
{
	t_stack	*aux;
	int		index;

	aux = stack;
	index = 0;
	while (aux)
	{
		if (aux->num == min)
			return (index);
		aux = aux->next;
		index++;
	}
	return (-1);
}

int	ft_divider(float size, float div)
{
	int		k;
	float	res;

	res = size / div;
	k = (int)res;
	if ((res - k) >= 0.5)
		return ((int)res + 1);
	else
		return ((int)res);
}

void	find_rotate_move(t_stack **stack_a, t_stack **stack_b, long nbr)
{
	int	proxy;
	int	index;

	while ((*stack_a)->num != nbr)
	{
		proxy = ft_stack_size(*stack_a) / 2;
		index = get_index(*stack_a, nbr);
		if (proxy >= index)
			choose_move(stack_a, stack_b, "ra");
		else
			choose_move(stack_a, stack_b, "rra");
	}
}
