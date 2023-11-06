/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:00 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:01 by mguardia         ###   ########.fr       */
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

// Stack Moves
void    swap(t_stack **stack);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    push(t_stack **stack_src, t_stack **stack_dst);

// algorithm
int ft_is_sort(t_stack *stack_a, int size);


#endif