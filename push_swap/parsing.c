/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:47:58 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/04 17:56:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void    ft_print_stack(char **stack)
// {
//     int i = 0;

//     while (stack[i])
//     {
//         ft_printf("%s\n", stack[i]);
//         i++;
//     }
// }

static long    ft_atol_strict(char **split, long i)
{
    long    result;
    int     j;
    int     sign;

    result = 0;
    j = 0;
    sign = 1;
    if (split[i][j] == '+' || split[i][j] == '-')
    {
        if (split[i][j] == '-')
            sign = -1;
        j++;
    }
    while (split[i][j])
    {
        if (!ft_isdigit(split[i][j]))
        {
            free_matrix((void **)split);
            ft_error();
        }
        result = result * 10 + split[i][j++] - '0';
    }
    if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
    {
        free_matrix((void **)split);
        ft_error();
    }
    return (result * sign);
}

void    manage_strings(t_stack **stack_a, char **split)
{
    long    i;
    long    num;

    (void)stack_a;
    i = 0;
    while (split[i])
    {
        num = ft_atol_strict(split, i);
        //fill_stack(stack_a, num);
        ft_printf("%d\n", num);
        i++;
    }
}

void    ft_parse_args(char **argv, t_stack **stack_a)
{
    long     i;
    char    **split;
    long    num;

    i = 0;
    (void)stack_a;
    while (argv[++i])
    {
        split = ft_split(argv[i], ' ');
        if (!split[1])
        {
            if (!split[0])
            {
                free_matrix((void **)split);
                ft_error();
            }
            num = ft_atol_strict(split, 0);
            //fill_stack(stack_a, num);
            ft_printf("%d\n", num);
        }
        else
            manage_strings(stack_a, split);
        free_matrix((void **)split);
    }
}
