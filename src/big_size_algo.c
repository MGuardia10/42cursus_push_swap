/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/15 20:58:50 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_two_to_b(t_stack **stack_a, t_stack **stack_b, int *size_a)
{
    choose_move(stack_a, stack_b, "pb");
    (*size_a)--;
    if ((*size_a) > 3 && !ft_is_sort(*stack_a))
    {
        choose_move(stack_a, stack_b, "pb");
        (*size_a)--;
    }
}

t_stack	*find_target(t_stack *node, t_stack *stack_a)
{
	t_stack	*aux_a;
	t_stack	*target;
	long	closest_nbr;

	if (ft_is_max_or_min(node, stack_a))
        target = find_smallest(stack_a);
	else
	{
		aux_a = stack_a;
		closest_nbr = INT_MAX;
		while (aux_a)
		{
			if (aux_a->num > node->num)
			{
				if (aux_a->num <= closest_nbr)
					target = aux_a;
				closest_nbr = aux_a->num;
			}
			aux_a = aux_a->next;
		}
	}
	return (target);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		proxy_a;
	int		size_b;
	t_stack	*target;
	t_stack *first_a;

	first_a = *stack_a;
	size_b = ft_stack_size(*stack_b);
	while (size_b > 0)
	{
		get_idxs(stack_a, stack_b);
		proxy_a = ft_stack_size(*stack_a) / 2;
		target = find_target(*stack_b, *stack_a);
		// printf("stack a num ----> %ld\n", (*stack_a)->num);
		// printf("target num ----> %ld\n", target->num);
		// printf("target idx ----> %d\n", target->idx);
		// printf("proxy ----> %d\n", proxy_a);
		while ((*stack_a)->num != target->num)
		{
			if (target->idx <= proxy_a)
				choose_move(stack_a, stack_b, "ra");
			else
				choose_move(stack_a, stack_b, "rra");
		}
		choose_move(stack_a, stack_b, "pa");
		// ft_printf("stack_a\n-------\n");
		// ft_print_stack(*stack_a);
		// ft_printf("\nstack_b\n-------\n");
		// ft_print_stack(*stack_b);
		size_b--;
	}
}

void	rotate_till_is_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
	int		proxy;

	get_idxs(stack_a, stack_b);
	smallest = find_smallest(*stack_a);
	proxy = ft_stack_size(*stack_a) / 2;
	while (smallest != (*stack_a))
	{
		if (smallest->idx <= proxy)
			choose_move(stack_a, stack_b, "ra");
		else
			choose_move(stack_a, stack_b, "rra");
	}
}

void    big_size_algo(t_stack **stack_a, t_stack **stack_b, int size)
{
    push_two_to_b(stack_a, stack_b, &size);
    if (size != 3)
        push_till_three(stack_a, stack_b, size);
	if (!ft_is_sort(*stack_a))
    	sort_three(stack_a, stack_b);
	// ft_printf("stack_a\n-------\n");
	// ft_print_stack(*stack_a);
	// ft_printf("\nstack_b\n-------\n");
	// ft_print_stack(*stack_b);
    push_to_a(stack_a, stack_b);
    if (!ft_is_sort_size(*stack_a, ft_stack_size(*stack_a)))
        rotate_till_is_sort(stack_a, stack_b);
}


/*
- get_idxs() OK
- buscar el cheapest node OK
- nbr y el idx y el num moves
- si el nodo idx > size /2 -> rra / rrr
- si el nodo idx <= size /2 -> ra / rr
- en cada push restar uno a size y recalcular indices
*/