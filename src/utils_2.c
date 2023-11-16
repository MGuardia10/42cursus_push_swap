/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:55:31 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 19:55:10 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_print_stack(t_stack *stack)
// {
// 	t_stack	*aux;

// 	aux = stack;
// 	while (aux)
// 	{
// 		printf("%ld\n", aux->num);
// 		aux = aux->next;
// 	}
// }

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

int	ft_count_moves(t_stack *node, t_stack *a, t_stack *b, int proxy_a)
{
	int		count;
	int		flag;
	t_stack	*closest_node_b;
	int		proxy_b;

	count = 0;
	flag = 0;
	closest_node_b = find_closest(node, b);
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
	count += count_b_moves(closest_node_b, b, count, flag);
	return (count);
}

int	count_b_moves(t_stack *node, t_stack *b, int count, int flag)
{
	int	index;
	int	proxy_b;

	index = node->idx;
	proxy_b = ft_stack_size(b) / 2;
	if (flag == 0 && node->idx <= proxy_b)
		return (count_upper_moves(count, index));
	else if (flag == 1 && node->idx >= proxy_b)
		return (count_lower_moves(count, index, b));
	else if (node->idx < proxy_b)
		return (index);
	else
		return (ft_stack_size(b) - index);
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
