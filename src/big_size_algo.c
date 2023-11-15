/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/15 10:12:36 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_two_to_b(t_stack **stack_a, t_stack **stack_b, int *size_a)
{
    choose_move(stack_a, stack_b, "pb");
    (*size_a)--;
    if ((*size_a) > 3)
    {
        choose_move(stack_a, stack_b, "pb");
        (*size_a)--;
    }
}

int	count_upper_moves(int count, int index)
{
	while (count > 0 && index > 0)
	{
		count--;
		index--;
	}
	if (count == 0)
		return (index);
	else
		return (0);
}

int	count_lower_moves(int count, int index, t_stack *b)
{
	while ((count > 0) && ((ft_stack_size(b) - index) > 0))
	{
		count--;
		index++;
	}
	if (count == 0)
		return (ft_stack_size(b) - index);
	else
		return (0);
}

int	count_b_moves(t_stack *node, t_stack *b, int proxy_b, int count, int flag)
{
	int	index;

	index = node->idx;
	if (flag == 0 && node->idx <= proxy_b)
		return (count_upper_moves(count, index));
	else if (flag == 1 && node->idx >= proxy_b)
		return (count_lower_moves(count, index, b));
	else if (node->idx < proxy_b)
		return (index);
	else
		return (ft_stack_size(b) - index);
}

t_stack	*find_closest(t_stack *node, t_stack *b)
{
	t_stack	*aux;
	long	closest_nbr;

    if (ft_is_max_or_min(node, b))
        node->target = find_biggest(b);
    else
    {
		aux = b;
		closest_nbr = INT_MIN;
        while (aux)
        {
            if (aux->num < node->num)
			{
				if (aux->num >= closest_nbr)
					node->target = aux;
				closest_nbr = aux->num;
			}
            aux = aux->next;
        }
    }
    return (node->target);
}

int	ft_count_moves(t_stack *node, t_stack *a, t_stack *b, int proxy_a)
{
	int		count;
	int		flag;
	t_stack	*closest_node_b;
	int		proxy_b;

	count = 0;
	flag = 0;
	closest_node_b = find_closest(node, b);
    printf("\nnbr closest node -> %ld", closest_node_b->num);
	proxy_b = ft_stack_size(b) / 2;
	if (node->idx <= proxy_a)
	{
		count = node->idx;
		flag = 0;
	}
	else
	{
		count = ft_stack_size(a) - node->idx;
		flag = 1;
	}
	count += count_b_moves(closest_node_b, b, proxy_b, count, flag);
    printf("\nnbr candidate node -> %ld", node->num);
    printf("\ntotal count -> %d\n", count);
	return (count);

}

t_stack	*find_cheapest(t_stack **stack_a, t_stack **stack_b, int proxy)
{
	t_stack	*aux_a;
	t_stack	*cheapest;
	int		count;
	int		min_count;

	aux_a = *stack_a;
	min_count = INT_MAX;
	while (aux_a)
	{
		count = ft_count_moves(aux_a, *stack_a, *stack_b, proxy);
		if (count == 0)
			return (aux_a);
		if (count < min_count)
		{
			min_count = count;
			cheapest = aux_a;
		}
		aux_a = aux_a->next;
	}
	return (cheapest);
}

// void    rotate_ab_to_cheapest(t_stack **a, t_stack **b, t_stack *cheap, int proxy)
// {

// }

void    push_till_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*cheapest;
	int		proxy;

	while (size > 3)
	{
		get_idxs(*stack_a, *stack_b);
		proxy = size / 2;
		if (ft_is_max_or_min(*stack_a, *stack_b))
		{
			rotate_b_to_max(stack_a, stack_b, proxy);
			choose_move(stack_a, stack_b, "pb");
		}
		else
		{
            ft_printf("stack_a\n-------\n");
            ft_print_stack(*stack_a);
            ft_printf("\nstack_b\n-------\n");
            ft_print_stack(*stack_b);
			cheapest = find_cheapest(stack_a, stack_b, proxy);
            printf("\nnbr chepaest node -> %ld", cheapest_node->num);
            printf("\nidx chepaest node -> %d\n", cheapest_node->idx);
			// while (cheapest_node != (*stack_a) && )
			//     rotate_ab_to_cheapest(stack_a, stack_b, cheapest_node, proxy);
			//choose_move(stack_a, stack_b, "pb");
		}
		size--;
	}
}

void    big_size_algo(t_stack **stack_a, t_stack **stack_b, int size)
{
    push_two_to_b(stack_a, stack_b, &size);
    if (size != 3)
        push_till_three(stack_a, stack_b, size);
	// if (!ft_is_sort(*stack_a))
    // 	sort_three(stack_a, stack_b);
    // push_to_a();
    // if (!ft_is_sort_size(stack_a, ft_stack_size(*stack_a)))
    //     rotate_till_is_sort(stack_a);
}


/*
- get_idxs() OK
- buscar el cheapest node OK
- nbr y el idx y el num moves
- si el nodo idx > size /2 -> rra / rrr
- si el nodo idx <= size /2 -> ra / rr
- en cada push restar uno a size y recalcular indices
*/