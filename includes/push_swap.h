/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:00 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/05 12:39:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
    long            num;
    long            index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// parsing arguments
void    ft_parse_args(char **argv, t_stack **stack_a);
void    free_matrix(char **p);
void    check_doubles(t_stack *stack_a);

// list utils
void    fill_stack(t_stack **stack_a, long num);
t_stack *ft_stack_last(t_stack *stack);
void    ft_stack_clear(t_stack **stack);
int     ft_stack_size(t_stack *stack);


#endif