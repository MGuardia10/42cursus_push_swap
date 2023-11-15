/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:05 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/15 13:05:12 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_move3(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "ss", ft_strlen(str)) == 0)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	else if (ft_strncmp(str, "rr", ft_strlen(str)) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	else if (ft_strncmp(str, "rrr", ft_strlen(str)) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
}

static void	choose_move2(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "ra", ft_strlen(str)) == 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (ft_strncmp(str, "rb", ft_strlen(str)) == 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (ft_strncmp(str, "rra", ft_strlen(str)) == 0)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if (ft_strncmp(str, "rrb", ft_strlen(str)) == 0)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
	else
		choose_move3(stack_a, stack_b, str);
}

void	choose_move(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "sa", ft_strlen(str)) == 0)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (ft_strncmp(str, "sb", ft_strlen(str)) == 0)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (ft_strncmp(str, "pa", ft_strlen(str)) == 0)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (ft_strncmp(str, "pb", ft_strlen(str)) == 0)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
		choose_move2(stack_a, stack_b, str);
}
