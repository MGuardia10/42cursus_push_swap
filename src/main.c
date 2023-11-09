/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/09 20:21:37 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void    f(void)
// {
//     system("leaks -q push_swap");
// }

static void    ft_manage_algorithms(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size <= 10)
        small_size_algo(stack_a, stack_b, size, 1);
    else if (size > 10 && size <= 200)
        big_size_algo(stack_a, stack_b, size, 4);
    else
        big_size_algo(stack_a, stack_b, size, 8);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

    //atexit(f);
    stack_a = NULL;
    stack_b = NULL;
    if (argc > 1)
    {
        // args parsing
        ft_parse_args(argv, &stack_a);
        // check is sorted
        size = ft_stack_size(stack_a);
        if (ft_is_sort_size(stack_a, size))
        {
            ft_stack_clear(&stack_a);
            exit(0);
        }
        // choose algorithm base on size of stack_a
        ft_manage_algorithms(&stack_a, &stack_b, size);

        // ft_printf("stack_a\n-------\n");
        // ft_print_stack(stack_a);
        // ft_printf("\nstack_b\n-------\n");
        // ft_print_stack(stack_b);

        // Cleaning stacks
        ft_stack_clear(&stack_a);
        ft_stack_clear(&stack_b);
        return (0);
    }
    return (1);
}
