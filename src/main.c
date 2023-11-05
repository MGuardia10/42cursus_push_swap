/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/05 12:41:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_matrix(char **p)
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
    system("leaks -q push_swap");
}

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

int main(int argc, char **argv)
{
    t_stack *stack_a;
    // t_stack *stack_b;

    stack_a = NULL;
    // stack_b = NULL;

    atexit(f);
    if (argc > 1)
    {
        ft_parse_args(argv, &stack_a);
        check_doubles(stack_a);
        // push swap logic
        

        ft_print_stack(stack_a);
        ft_stack_clear(&stack_a);
    }
    return (0);
}
