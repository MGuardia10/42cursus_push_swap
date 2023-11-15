/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_till_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:23:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/15 20:57:20 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_cheapest(t_stack **stack_a, t_stack **stack_b, int proxy)
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

static void	rotate_b_to_max(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*biggest_node;
	int		proxy;

	biggest_node = find_biggest(*stack_b);
	proxy = ft_stack_size(*stack_b) / 2;
	while ((*stack_b) != biggest_node)
	{
		if (biggest_node->idx <= proxy)
			choose_move(stack_a, stack_b, "rb");
		else
			choose_move(stack_a, stack_b, "rrb");
	}
}

static void    rotate_ab_to_cheapest(t_stack **a, t_stack **b, t_stack *cheap, int proxy_a)
{
	t_stack	*target;
	int		proxy_b;

	target = cheap->target;
	proxy_b = ft_stack_size(*b) / 2;
	if ((*a) != cheap)
	{
		if (cheap->idx <= proxy_a)
		{
			if (target->idx <= proxy_b && target != (*b))
				choose_move(a, b, "rr");
			else
				choose_move(a, b, "ra");
		}
		else
		{
			if (target->idx >= proxy_b && target != (*b)) // ?? =
				choose_move(a, b, "rrr");
			else
				choose_move(a, b, "rra");
		}
	}
	else if ((*b) != target)
	{
		if (target->idx <= proxy_b)
			choose_move(a, b, "rb");
		else
			choose_move(a, b, "rrb");
	}
}

void    push_till_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*cheapest;
	int		proxy;

	while (size > 3 && !ft_is_sort(*stack_a))
	{
		get_idxs(stack_a, stack_b);
		proxy = size / 2;
		if (ft_is_max_or_min(*stack_a, *stack_b))
		{
			rotate_b_to_max(stack_a, stack_b);
			choose_move(stack_a, stack_b, "pb");
		}
		else
		{
            // ft_printf("stack_a\n-------\n");
            // ft_print_stack(*stack_a);
            // ft_printf("\nstack_b\n-------\n");
            // ft_print_stack(*stack_b);
			cheapest = find_cheapest(stack_a, stack_b, proxy);
            // printf("\nnbr cheapest node -> %ld", cheapest->num);
            // printf("\nnbr target node -> %ld\n", cheapest->target->num);
            // printf("idx cheapest node -> %d\n", cheapest->idx);
            // printf("idx target node -> %d\n", cheapest->target->idx);
			while (cheapest != (*stack_a) || cheapest->target != (*stack_b))
			    rotate_ab_to_cheapest(stack_a, stack_b, cheapest, proxy);
			choose_move(stack_a, stack_b, "pb");
		}
		size--;
	}
}