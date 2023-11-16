/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:05 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 17:12:51 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_move3(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == 8)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	else if (pos == 9)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	else if (pos == 10)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
}

static void	choose_move2(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == 4)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (pos == 5)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (pos == 6)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if (pos == 7)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else
		choose_move3(stack_a, stack_b, pos);
}

void	choose_move(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == 0)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (pos == 1)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (pos == 2)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (pos == 3)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
		choose_move2(stack_a, stack_b, pos);
}
