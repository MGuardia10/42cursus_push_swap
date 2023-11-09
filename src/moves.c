/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:13:26 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/09 19:48:09 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *aux;
    int     nbr;

    if (!(*stack) || !(*stack)->next)
        return ;
    aux = *stack;
    nbr = aux->num;
    aux->num = aux->next->num;
    aux->next->num = nbr;
}

void    push(t_stack **stack_src, t_stack **stack_dst)
{
    t_stack *new_node;
    t_stack *aux;

    if (!stack_dst || !(*stack_src))
        return ;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    aux = *stack_src; // nodo stack a
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

void    rotate(t_stack **stack)
{
    t_stack *aux1;
    t_stack *aux2;

    if (!(*stack))
        return ;
    // Si no cambio el *stack al siguiente nodo, el puntero de la lista al finalizar esta funcion
    // apuntaría al ultimo nodo y empezaría a leer desde ahi.
    *stack = (*stack)->next;
    aux1 = *stack;
    aux2 = (*stack)->prev;
    while (aux1->next)
        aux1 = aux1->next;
    aux1->next = aux2;
    aux2->prev = aux1;
    aux1->next->next = NULL;
}

void    reverse_rotate(t_stack **stack)
{
    t_stack *aux1;
    t_stack *aux2;

    if (!(*stack))
        return ;
    aux1 = *stack; // primero
    // apuntar stack al que va a ser el primer nodo de la lista
    while ((*stack)->next)
        *stack = (*stack)->next;
    aux2 = *stack; // ultimo
    aux2->prev->next = NULL;
    aux2->next = aux1;
    aux2->prev = NULL;
    aux2->next->prev = aux2;
}
