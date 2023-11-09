/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:00 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:51 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
    long            num;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// parsing arguments
void    ft_parse_args(char **argv, t_stack **stack_a);

// list utils
void    fill_stack(t_stack **stack_a, long num);
t_stack *ft_stack_last(t_stack *stack);
void    ft_stack_clear(t_stack **stack);
int     ft_stack_size(t_stack *stack);
void	ft_stack_add_front(t_stack **stack, t_stack *new);

// utils
int		check_sign(char **split, long i, int *j);
void    check_fit_int(long result, char **split);
long	get_min(t_stack *stack);
int		ft_is_sort_size(t_stack *stack_a, int size);
int		ft_is_sort(t_stack *stack_a);
void	ft_print_stack(t_stack *stack_a);
int		get_index(t_stack *stack, long min);
int		ft_divider(float size, float div);


// Stack Moves
void    swap(t_stack **stack);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    push(t_stack **stack_src, t_stack **stack_dst);

// algorithm
void    choose_move(t_stack **stack_a, t_stack **stack_b, char *str);
void    sort_three(t_stack **stack_a);
void    small_size_algo(t_stack **stack_a, t_stack **stack_b, int size, int f);
void    big_size_algo(t_stack **stack_a, t_stack **stack_b, int size, int div);

#endif