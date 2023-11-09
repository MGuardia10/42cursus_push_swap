/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:31 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/08 11:04:33 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_print_stack(t_stack *stack)
{
    t_stack *aux;

    aux = stack;
    while (aux)
    {
        ft_printf("%d\n", aux->num);
        aux = aux->next;
    }
}

int get_index(t_stack *stack, long min)
{
    t_stack *aux;
    int     index;

    aux = stack;
    index = 0;
    while (aux)
    {
        if (aux->num == min)
            return (index);
        aux = aux->next;
        index++;
    }
    return (-1);
}

int ft_divider(float size, float div)
{
    int   k;
    float res;

    res = size / div;
    k = (int) res;
    if ((res - k) >= 0.5)
		return ((int)res + 1);
	else
		return ((int)res);
}