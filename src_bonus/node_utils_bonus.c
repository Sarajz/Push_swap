/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:02:52 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 18:04:19 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_stack_node	*ft_lstnew(int digit)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc (sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->digit = digit;
	new->next = NULL;
	return (new);
}

t_stack_node	*cheapest_a(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->digit < cheapest_value)
		{
			cheapest_value = stack->digit;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	init_node(t_stack_node **a, t_stack_node **b)
{
	put_index(*a);
	put_index(*b);
	set_target_b(*a, *b);
	cost_analysis(*a, *b);
}
