/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:03 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 18:58:02 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_two_to_b(t_stack **stack_a, t_stack **stack_b, int *size_a)
{
	choose_move(stack_a, stack_b, 3);
	(*size_a)--;
	if ((*size_a) > 3 && !ft_is_sort(*stack_a))
	{
		choose_move(stack_a, stack_b, 3);
		(*size_a)--;
	}
}
