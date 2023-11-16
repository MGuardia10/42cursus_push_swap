/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:57 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 19:14:17 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_target(t_stack *node, t_stack *stack_a)
{
	t_stack	*aux_a;
	t_stack	*target;
	long	closest_nbr;

	if (ft_is_max_or_min(node, stack_a))
		target = find_smallest(stack_a);
	else
	{
		aux_a = stack_a;
		closest_nbr = INT_MAX;
		while (aux_a)
		{
			if (aux_a->num > node->num)
			{
				if (aux_a->num <= closest_nbr)
					target = aux_a;
				closest_nbr = aux_a->num;
			}
			aux_a = aux_a->next;
		}
	}
	return (target);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		proxy_a;
	int		proxy_b;
	int		size_b;
	t_stack	*target;
	t_stack	*first_a;

	first_a = *stack_a;
	size_b = ft_stack_size(*stack_b);
	while (size_b > 0)
	{
		get_idxs(stack_a, stack_b);
		proxy_a = ft_stack_size(*stack_a) / 2;
		proxy_b = ft_stack_size(*stack_b) / 2;
		target = find_target(*stack_b, *stack_a);
		while ((*stack_a)->num != target->num)
		{
			if (target->idx <= proxy_a)
				choose_move(stack_a, stack_b, 4);
			else
				choose_move(stack_a, stack_b, 6);
		}
		choose_move(stack_a, stack_b, 2);
		size_b--;
	}
}
