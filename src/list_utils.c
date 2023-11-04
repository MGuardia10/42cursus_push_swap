/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/04 20:26:52 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *ft_stacklast(t_stack *stack)
{
    t_stack *aux;

    aux = stack;
    while (stack != NULL)
    {
        aux = stack;
        stack = stack->next;
    }
    return (aux);
}

void    ft_stack_clear(t_stack **stack)
{
    if (!stack || !(*stack))
        return ;
    ft_stack_clear(&(*stack)->next);
    free(*stack);
    *stack = NULL;
}