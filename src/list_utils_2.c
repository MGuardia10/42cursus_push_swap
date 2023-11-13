/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:14 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_idxs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		idx;

	aux_a = stack_a;
	aux_b = stack_b;
	idx = 0;
	while (aux_a)
	{
		aux_a->idx = idx;
		aux_a = aux_a->next;
		idx++;
	}
	idx = 0;
	while (aux_b)
	{
		aux_b->idx = idx;
		aux_b = aux_b->next;
		idx++;
	}
}

int	ft_is_max_or_min(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*aux;
	int		min;
	int		max;

	aux = stack_b;
	min = stack_a->num;
	max = stack_a->num;
	while (aux)
	{
		if (aux->num > max)
			max = aux->num;
		if (aux->num < min)
			min = aux->num;
		if (max != stack_a->num && min != stack_a->num)
			return (0);
		aux = aux->next;
	}
	return (1);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*aux;

	max_node = NULL;
	aux = stack;
	while (aux)
	{
		if (!max_node)
			max_node = aux;
		if (max_node->num < aux->num)
			max_node = aux;
		aux = aux->next;
	}
	return (max_node);
}

void	rotate_b_to_max(t_stack **stack_a, t_stack **stack_b, int proxy)
{
	t_stack	*bigest_node;

	bigest_node = find_biggest(*stack_b);
	while ((*stack_b) != bigest_node)
	{
		if (bigest_node->idx <= proxy)
			choose_move(stack_a, stack_b, "rb");
		else
			choose_move(stack_a, stack_b, "rrb");
	}
}
