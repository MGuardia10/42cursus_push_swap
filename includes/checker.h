/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:05:43 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/17 12:20:52 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	long			num;
	int				idx;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// parsing arguments
void	ft_parse_args_checker(char **argv, t_stack **stack_a);

// list utils
void	fill_stack(t_stack **stack, long num);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_clear(t_stack **stack);
int		ft_stack_size(t_stack *stack);
void	ft_stack_add_front(t_stack **stack, t_stack *new);

// utils
int		check_sign(char **split, long i, int *j);
void	check_fit_int(long result, char **split);
int     ft_is_sort(t_stack *stack_a);

// stack moves
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_src, t_stack **stack_dst);
void	choose_move_c(t_stack **stack_a, t_stack **stack_b, char *str);

#endif