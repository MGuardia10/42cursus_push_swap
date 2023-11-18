/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 10:54:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void    f(void)
// {
//     system("leaks -q push_swap");
// }

static void	big_size_algo(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_two_to_b(stack_a, stack_b, &size);
	if (size != 3)
		push_till_three(stack_a, stack_b, size);
	if (!ft_is_sort(*stack_a))
		sort_three(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	if (!ft_is_sort_size(*stack_a, ft_stack_size(*stack_a)))
		rotate_till_is_sort(stack_a, stack_b);
}

static void	ft_manage_algorithms(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && ((*stack_a)->num > (*stack_a)->next->num))
		choose_move(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else
		big_size_algo(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		ft_parse_args(argv, &stack_a);
		size = ft_stack_size(stack_a);
		if (ft_is_sort_size(stack_a, size))
		{
			ft_stack_clear(&stack_a);
			exit(0);
		}
		ft_manage_algorithms(&stack_a, &stack_b, size);
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (0);
	}
	return (1);
}
