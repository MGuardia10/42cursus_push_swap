/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:17 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/17 23:20:54 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	read_stdin(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		choose_move_c(stack_a, stack_b, str);
		free(str);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		ft_parse_args_checker(argv, &stack_a);
		if (!stack_a)
			ft_error();
		read_stdin(&stack_a, &stack_b);
		if (ft_is_sort(stack_a) && ft_stack_size(stack_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_stack_clear(&stack_a);
		ft_stack_clear(&stack_b);
		return (0);
	}
	return (1);
}
