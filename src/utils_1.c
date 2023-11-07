/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:24:53 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/07 10:55:50 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_sign(char **split, long i, int *j)
{
    int sign;

    sign = 1;
    if (split[i][*j] == '+' || split[i][*j] == '-')
    {
        if (!split[i][*j + 1])
        {
            ft_free_matrix(split);
            ft_error();
        }
        if (split[i][*j] == '-')
            sign = -1;
        (*j)++;
    }
    return (sign);
}

void    check_fit_int(long result, char **split)
{
    if (result < INT_MIN || result > INT_MAX)
    {
        ft_free_matrix(split);
        ft_error();
    }
}

long    get_min(t_stack *stack)
{
    t_stack *aux;
    long    min;

    aux = stack;
    min = stack->num;
    while (aux)
    {
        if (aux->num < min)
            min = aux->num;
        aux = aux->next;
    }
    return (min);
}

int ft_is_sort_size(t_stack *stack_a, int size)
{
    t_stack *aux;

    aux = stack_a;
    if (ft_stack_size(aux) < size)
        return (0);
    while (aux->next)
    {
        if (aux->num > aux->next->num)
            return (0);
        aux = aux->next;
    }
    return (1);
}

int ft_is_sort(t_stack *stack_a)
{
    t_stack *aux;

    aux = stack_a;
    while (aux->next)
    {
        if (aux->num > aux->next->num)
            return (0);
        aux = aux->next;
    }
    return (1);
}
