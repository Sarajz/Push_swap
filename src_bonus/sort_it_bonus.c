/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:32:22 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 18:04:27 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->digit > stack->next->digit)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->digit > (*a)->next->digit)
		sa(a);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tar_a;

	while (stack_len(*a) > 3)
	{
		if ((*a)->digit < num_media(*a))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
	{
		init_node(a, b);
		move_node(a, b);
		pa(a, b);
	}
	tar_a = cheapest_a(*a);
	while (*a != tar_a)
	{
		if (tar_a->above_median)
			ra(a);
		else
			rra(a);
	}
}
