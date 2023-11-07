/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:33:05 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/06 18:48:33 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void    choose_move2(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if (ft_strncmp(str, "ra", 2) == 0)
    {
        rotate(stack_a);
        ft_printf("ra\n");
    }
    else if (ft_strncmp(str, "rb", 2) == 0)
    {
        rotate(stack_b);
        ft_printf("rb\n");
    }
    else if (ft_strncmp(str, "rra", 3) == 0)
    {
        reverse_rotate(stack_a);
        ft_printf("rra\n");
    }
    else if (ft_strncmp(str, "rrb", 3) == 0)
    {
        reverse_rotate(stack_b);
        ft_printf("rrb\n");
    }
}

void    choose_move(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if (ft_strncmp(str, "sa", 2) == 0)
    {
        swap(stack_a);
        ft_printf("sa\n");
    }
    else if (ft_strncmp(str, "sb", 2) == 0)
    {
        swap(stack_b);
        ft_printf("sb\n");
    }
    else if (ft_strncmp(str, "pa", 2) == 0)
    {
        push(stack_b, stack_a);
        ft_printf("pa\n");
        
    }
    else if (ft_strncmp(str, "pb", 2) == 0)
    {
        push(stack_a, stack_b);
        ft_printf("pb\n");
    }
    else
        choose_move2(stack_a, stack_b, str);
}
