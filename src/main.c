/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/16 17:18:45 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void    f(void)
// {
//     system("leaks -q push_swap");
// }

void	ft_manage_algorithms(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && ((*stack_a)->num > (*stack_a)->next->num))
		choose_move(stack_a, stack_b, 0);
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

	//atexit(f);
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
		// printf("stack_a\n-------\n");
		// ft_print_stack(stack_a);
		// printf("\nstack_b\n-------\n");
		// ft_print_stack(stack_b);
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (0);
	}
	return (1);
}
