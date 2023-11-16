/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:07 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 17:17:10 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack_a)->num;
	num2 = (*stack_a)->next->num;
	num3 = (*stack_a)->next->next->num;
	if (num1 > num2 && num2 < num3 && num1 < num3)
		choose_move(stack_a, stack_b, 0);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		choose_move(stack_a, stack_b, 0);
		choose_move(stack_a, stack_b, 6);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		choose_move(stack_a, stack_b, 4);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		choose_move(stack_a, stack_b, 0);
		choose_move(stack_a, stack_b, 4);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		choose_move(stack_a, stack_b, 6);
}
