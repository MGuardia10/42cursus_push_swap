/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:47:00 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/04 20:27:11 by mguardia         ###   ########.fr       */
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
void    free_matrix(void **p);

// list utils
t_stack *ft_stacklast(t_stack *stack);
void    ft_stack_clear(t_stack **stack);

#endif