/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:56:53 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/30 20:27:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_lstnew creates a new node for a linked list with the given content.
 * 
 * @param content The "content" parameter is a void pointer that represents the data that will be
 * stored in the new node of the linked list. It can be any type of data, as it is a void pointer.
 * 
 * @return The function `ft_lstnew` returns a pointer to a newly created `t_list` node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*aux;

	aux = (t_list *)malloc(sizeof(t_list));
	if (!aux)
		return (NULL);
	aux->content = content;
	aux->next = NULL;
	return (aux);
}