/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:28:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 19:52:24 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_cheapest(t_stack **stack_a, t_stack **stack_b, int proxy)
{
	t_stack	*aux_a;
	t_stack	*cheapest;
	int		count;
	int		min_count;

	aux_a = *stack_a;
	min_count = INT_MAX;
	while (aux_a)
	{
		count = ft_count_moves(aux_a, *stack_a, *stack_b, proxy);
		if (count == 0)
			return (aux_a);
		if (count < min_count)
		{
			min_count = count;
			cheapest = aux_a;
		}
		aux_a = aux_a->next;
	}
	return (cheapest);
}
