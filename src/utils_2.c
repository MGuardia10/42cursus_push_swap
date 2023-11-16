/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:31 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 16:26:32 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		printf("%ld\n", aux->num);
		aux = aux->next;
	}
}

int	get_index(t_stack *stack, long min)
{
	t_stack	*aux;
	int		index;

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

void	find_rotate_move(t_stack **stack_a, t_stack **stack_b, long nbr)
{
	int	proxy;
	int	index;

	while ((*stack_a)->num != nbr)
	{
		proxy = ft_stack_size(*stack_a) / 2;
		index = get_index(*stack_a, nbr);
		if (proxy >= index)
			choose_move(stack_a, stack_b, "ra");
		else
			choose_move(stack_a, stack_b, "rra");
	}
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
				{
					node->target = aux;
					closest_nbr = aux->num;
				}
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
    //printf("\nnbr closest node -> %ld", closest_node_b->num);
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
    // printf("\nnbr candidate node -> %ld", node->num);
    // printf("\ntotal count -> %d\n", count);
	return (count);
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
