/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:11:02 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 10:47:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	fill_stack(t_stack **stack, long num)
{
	t_stack	*last_node;
	t_stack	*new_node;

	last_node = ft_stack_last(*stack);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (ft_stack_clear(stack));
	if (!last_node)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	new_node->num = num;
	new_node->target = NULL;
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
	}
	return (aux);
}

void	ft_stack_clear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_stack_clear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
