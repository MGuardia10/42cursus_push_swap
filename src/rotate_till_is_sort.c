/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_till_is_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/17 10:03:06 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_till_is_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
	int		proxy;

	get_idxs(stack_a, stack_b);
	smallest = find_smallest(*stack_a);
	proxy = ft_stack_size(*stack_a) / 2;
	while (smallest != (*stack_a))
	{
		if (smallest->idx <= proxy)
			choose_move(stack_a, stack_b, "ra");
		else
			choose_move(stack_a, stack_b, "rra");
	}
}
