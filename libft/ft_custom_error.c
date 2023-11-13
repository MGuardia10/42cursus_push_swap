/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:01:40 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/13 14:51:50 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_custom_error(char *error)
{
	write(STDERR, "Error: ", 7);
	ft_putstr_fd(error, STDERR);
	exit(EXIT_FAILURE);
}
