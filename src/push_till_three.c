/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_till_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:23:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 19:45:53 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_a(t_stack **a, t_stack **b, t_stack *cheap, t_stack *target)
{
	int	proxy_a;
	int	proxy_b;

	proxy_a = ft_stack_size(*a) / 2;
	proxy_b = ft_stack_size(*b) / 2;
	if (cheap->idx <= proxy_a)
	{
		if (target->idx <= proxy_b && target != (*b))
			choose_move(a, b, 9);
		else
			choose_move(a, b, 4);
	}
	else
	{
		if (target->idx > proxy_b && target != (*b))
			choose_move(a, b, 10);
		else
			choose_move(a, b, 6);
	}
}

static void	rotate_b(t_stack **a, t_stack **b, t_stack *target)
{
	int	proxy_b;

	proxy_b = ft_stack_size(*b) / 2;
	if (target->idx <= proxy_b)
		choose_move(a, b, 5);
	else
		choose_move(a, b, 7);
}

static void	rotate_ab_to_cheapest(t_stack **a, t_stack **b, t_stack *cheap)
{
	t_stack	*target;

	target = cheap->target;
	if ((*a) != cheap)
		rotate_a(a, b, cheap, target);
	else if ((*b) != target)
		rotate_b(a, b, target);
}

void	push_till_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*cheapest;
	int		proxy;

	while (size > 3 && !ft_is_sort(*stack_a))
	{
		get_idxs(stack_a, stack_b);
		proxy = ft_stack_size(*stack_a) / 2;
		cheapest = find_cheapest(stack_a, stack_b, proxy);
		while (cheapest != (*stack_a) || cheapest->target != (*stack_b))
			rotate_ab_to_cheapest(stack_a, stack_b, cheapest);
		choose_move(stack_a, stack_b, 3);
		size--;
	}
}
