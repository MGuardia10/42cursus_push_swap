/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:13:26 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/13 15:05:30 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*aux;
	int		nbr;

	if (!(*stack) || !(*stack)->next)
		return ;
	aux = *stack;
	nbr = aux->num;
	aux->num = aux->next->num;
	aux->next->num = nbr;
}

void	push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*new_node;
	t_stack	*aux;

	if (!stack_dst || !(*stack_src))
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	aux = *stack_src;
	new_node->num = (*stack_src)->num;
	new_node->prev = NULL;
	(*stack_src)->prev = NULL;
	if ((*stack_src)->next)
		*stack_src = (*stack_src)->next;
	else
		*stack_src = NULL;
	if (!(*stack_dst))
	{
		*stack_dst = new_node;
		(*stack_dst)->next = NULL;
	}
	else
		ft_stack_add_front(stack_dst, new_node);
	free(aux);
}

void	rotate(t_stack **stack)
{
	t_stack	*aux1;
	t_stack	*aux2;

	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	aux1 = *stack;
	aux2 = (*stack)->prev;
	while (aux1->next)
		aux1 = aux1->next;
	aux1->next = aux2;
	aux2->prev = aux1;
	aux1->next->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*aux1;
	t_stack	*aux2;

	if (!(*stack))
		return ;
	aux1 = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	aux2 = *stack;
	aux2->prev->next = NULL;
	aux2->next = aux1;
	aux2->prev = NULL;
	aux2->next->prev = aux2;
}
