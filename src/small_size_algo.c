/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:07 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/09 14:30:10 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_stack **stack_a)
{
    int num1;
    int num2;
    int num3;

    num1 = (*stack_a)->num;
    num2 = (*stack_a)->next->num;
    num3 = (*stack_a)->next->next->num;
    if (num1 > num2 && num2 < num3 && num1 < num3)
        choose_move(stack_a, NULL, "sa");
    else if (num1 > num2 && num2 > num3 && num1 > num3)
    {
        choose_move(stack_a, NULL, "sa");
        choose_move(stack_a, NULL, "rra");
    }
    else if (num1 > num2 && num2 < num3 && num1 > num3)
        choose_move(stack_a, NULL, "ra");
    else if (num1 < num2 && num2 > num3 && num1 < num3)
    {
        choose_move(stack_a, NULL, "sa");
        choose_move(stack_a, NULL, "ra");
    }
    else if (num1 < num2 && num2 > num3 && num1 > num3)
        choose_move(stack_a, NULL, "rra");
}

void    algo_10(t_stack **stack_a, t_stack **stack_b, int size)
{
        long    min_num;
        int     index;
        int     proxy;
        t_stack *second_node;

        while (size > 3 && !ft_is_sort(*stack_a))
        {
            min_num = get_min(*stack_a);
            second_node = (*stack_a)->next;
            if ((*stack_a)->num != min_num && second_node->num == min_num)
                choose_move(stack_a, stack_b, "sa");
            while ((*stack_a)->num != min_num)
            {
                proxy = ft_stack_size(*stack_a) / 2;
                index = get_index(*stack_a, min_num);
                if (proxy >= index)
                    choose_move(stack_a, stack_b, "ra");
                else
                    choose_move(stack_a, stack_b, "rra");
            }
            if ((*stack_a)->num == min_num)
                choose_move(stack_a, stack_b, "pb");
            size--;
        }
}

void    small_size_algo(t_stack **stack_a, t_stack **stack_b, int size, int f)
{
    if (size == 2)
    {
        if ((*stack_a)->num > (*stack_a)->next->num)
            choose_move(stack_a, stack_b, "sa");
    }
    else if (size == 3)
        sort_three(stack_a);
    else
    {
        algo_10(stack_a, stack_b, size);
        if (!ft_is_sort(*stack_a))
            sort_three(stack_a);
        if (f)
        {
            while (*stack_b)
                choose_move(stack_a, stack_b, "pa");
        }
    }
}
