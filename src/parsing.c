/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:47:58 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/04 20:31:11 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void    fill_stack(t_stack **stack_a, long num)
{
    t_stack *last_node;
    t_stack *new_node;
    static int     i;

    last_node = ft_stacklast(*stack_a);
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (free_matrix((void **)stack_a));
    if (!last_node)
    {
        *stack_a = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node->next = new_node;
        new_node->prev = last_node;
    }
    new_node->num = num;
    new_node->index = i;
    i++;
}

static void    check_fit_int(long result, char **split)
{
    if (result < INT_MIN || result > INT_MAX)
    {
        free_matrix((void **)split);
        ft_error();
    }
}

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
    result = result * sign;
    check_fit_int(result, split);
    return (result);
}

static void    manage_strings(t_stack **stack_a, char **split)
{
    long    i;
    long    num;

    i = 0;
    while (split[i])
    {
        num = ft_atol_strict(split, i);
        fill_stack(stack_a, num);
        i++;
    }
}

void    ft_parse_args(char **argv, t_stack **stack_a)
{
    long     i;
    char    **split;
    long    num;

    i = 0;
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
            fill_stack(stack_a, num);
        }
        else
            manage_strings(stack_a, split);
        free_matrix((void **)split);
    }
}
