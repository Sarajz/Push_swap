/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:32:51 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/14 17:48:48 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ab_error(t_stack_node **a, t_stack_node **b)
{
	if (*a)
		free (*a);
	if (*b)
		free (*b);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	a_error(t_stack_node **a)
{
	if (*a)
		free (*a);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_stack_node	*free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
	return (NULL);
}

void	ft_free_pointer(char **str)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
}
