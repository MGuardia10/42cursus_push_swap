/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/09 20:20:49 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    quicksort(long *k, int start, int end)
{
    int     left;
    int     right;
    long    pivot;
    long     aux;

    left = start;
    right = end;
    pivot = k[(left + right) / 2];
    while (left <= right)
    {
        while (k[left] < pivot && left < end)
            left++;
        while (k[right] > pivot && right > start)
            right--;
        if (left <= right)
        {
            aux = k[left];
            k[left++] = k[right];
            k[right--] = aux;
        }
    }
    if (start <= right)
        quicksort(k, start, right);
    if (left < end)
        quicksort(k, left, end);
}

void    ft_print_arr(long *arr_k)
{
    int i = 0;

    while (arr_k[i])
    {
        printf("%d -> %ld\n", i, arr_k[i]);
        i++;
    }
}

void    sort_arr_k(long *k, t_stack *a, int size)
{
    t_stack *aux;
    int     i;

    aux = a;
    i = 0;
    while (aux)
    {
        k[i] = aux->num;
        aux = aux->next;
        i++;
    }
    quicksort(k, 0, size - 1);
}

long    get_under_pivot(t_stack *stack, long key_nbr)
{
    t_stack *aux;

    aux = stack;
    while (aux)
    {
        if (aux->num <= key_nbr)
            return (1);
        aux = aux->next;
    }
    return (0);
}

long    get_number(t_stack *stack, long key_nbr)
{
    t_stack *aux;

    aux = stack;
    while (aux)
    {
        if (aux->num <= key_nbr)
            return (aux->num);
        aux = aux->next;
    }
    return (0);
}

long    get_max(t_stack *stack)
{
    t_stack *aux;
    long    max;

    aux = stack;
    max = stack->num;
    while (aux)
    {
        if (aux->num > max)
            max = aux->num;
        aux = aux->next;
    }
    return (max);
}

void    algo_200(t_stack **stack_a, t_stack **stack_b, long key_nbr, int *size)
{
    t_stack *second_node;
    int     proxy;
    int     index;
    long    nbr;

    while (get_under_pivot(*stack_a, key_nbr) && (*size) > 3 && !ft_is_sort(*stack_a))
    {
        nbr = get_number(*stack_a, key_nbr);
        second_node = (*stack_a)->next;
        if ((*stack_a)->num != nbr && second_node->num == nbr)
            choose_move(stack_a, stack_b, "sa");
        while ((*stack_a)->num != nbr)
        {
            proxy = ft_stack_size(*stack_a) / 2;
            index = get_index(*stack_a, nbr);
            if (proxy >= index)
                choose_move(stack_a, stack_b, "ra");
            else
                choose_move(stack_a, stack_b, "rra");
        }
        if ((*stack_a)->num == nbr)
            choose_move(stack_a, stack_b, "pb");
        (*size)--;
    }
}

void    push_from_b(t_stack **stack_a, t_stack **stack_b)
{
    long    max_num;
    t_stack *second_node;
    int     proxy;
    int     index;

    while (*stack_b)
    {
        max_num = get_max(*stack_b);
        second_node = (*stack_b)->next;
        if ((*stack_b)->num != max_num && second_node->num == max_num)
            choose_move(stack_a, stack_b, "sb");
        while ((*stack_b)->num != max_num)
        {
            proxy = ft_stack_size(*stack_b) / 2;
            index = get_index(*stack_b, max_num);
            if (proxy >= index)
                choose_move(stack_a, stack_b, "rb");
            else
                choose_move(stack_a, stack_b, "rrb");
        }
        if ((*stack_b)->num == max_num)
            choose_move(stack_a, stack_b, "pa");
    }
}

void    big_size_algo(t_stack **stack_a, t_stack **stack_b, int size, int div)
{
    long    *arr_k;
    int     key_index;
    int     i;
    long    key_nbr;
    int     len;

    arr_k = malloc(sizeof(long) * (size));
    if (!arr_k)
        return ;
    sort_arr_k(arr_k, *stack_a, size);
    key_index = 0;
    i = 1;
    len = size;
    while (i++ < div && !ft_is_sort(*stack_a) && size > 3)
    {
        key_index += ft_divider(len, div); // size cammbia hacer var len
        key_nbr = arr_k[key_index];
        // buscar nums en a por debajo de key_nbr y pasarlos a b (mientras q haya ocurrencias)
        // en cada bucle cambia el key_nbr para mas o menos pasarlos en orden al stack_b
        algo_200(stack_a, stack_b, key_nbr, &size);
    }
    // ordenar el 1/4 restante del stack_a si no está ordenado
    if (!ft_is_sort(*stack_a) && ft_stack_size(*stack_a) <= 10)
        small_size_algo(stack_a, stack_b, ft_stack_size(*stack_a), 0);
    else if (!ft_is_sort(*stack_a))
        big_size_algo(stack_a, stack_b, ft_stack_size(*stack_a), div);
    // en b tenemos numeros menores siempre que los de a, por lo que buscamos el numero mayor y usando el
    // metodo de proximidad lo subimos arriba para hacer pa finalmente, repetir hasta que b este vacio.
    if (*stack_b)
        push_from_b(stack_a, stack_b);

    // ft_printf("stack_a\n-------\n");
    // ft_print_stack(*stack_a);
    // ft_printf("\nstack_b\n-------\n");
    // ft_print_stack(*stack_b);

    
    free(arr_k);
}
