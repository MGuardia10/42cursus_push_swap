/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/04 12:53:54 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_matrix(void **p)
{
    int i;

    i = 0;
    while (p[i])
    {
        free(p[i]);
        i++;
    }
    free(p);
}

void    f(void)
{
    system("leaks -q a.out");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    // t_stack *stack_b;

    stack_a = NULL;
    // stack_b = NULL;

    atexit(f);
    if (argc > 1)
    {
        // parsing argv
        ft_parse_args(argv, &stack_a);
        // check doubles
        //check_doubles(&stack_a);
        // push swap logic
        //ft_print_stack(stack_a);
        //free_matrix(&stack_a);
    }
    return (0);
}

// validaciones
// - solo 1 arg -> no hace nada OK
// - checkear que sean solo numeros -> error
// - num se sale del rango de INT -> error
// - checkear que no haya repetidos -> error