/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:11:42 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/17 12:44:07 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	choose_move_c_2(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
	{
		ft_stack_clear(stack_a);
        ft_stack_clear(stack_b);
        free(str);
		ft_error();
	}
}

void	choose_move_c(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
    else
	    choose_move_c_2(stack_a, stack_b, str);
}
