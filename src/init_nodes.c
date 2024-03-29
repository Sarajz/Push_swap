/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:40:54 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/21 17:16:15 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

t_stack_node	*find_cheapest(t_stack_node *stack)

{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*aux_a;
	t_stack_node	*target_node;
	long			value_target_node;

	while (b)
	{
		value_target_node = LONG_MAX;
		aux_a = a;
		while (aux_a)
		{
			if (aux_a->digit > b->digit && aux_a->digit < value_target_node)
			{
				value_target_node = aux_a->digit;
				target_node = aux_a;
			}
			aux_a = aux_a->next;
		}
		b->target_node = target_node;
		b = b->next;
	}
}

static void	move_two_nodes(t_stack_node **a, t_stack_node **b,
		t_stack_node *tar)
{
	while ((tar->target_node->above_median && tar->above_median)
		&& (*a != tar->target_node && *b != tar))
		rr(a, b);
	while ((!tar->target_node->above_median && !tar->above_median)
		&& (ft_lstlast(*a) != tar->target_node && ft_lstlast(*b) != tar))
		rrr(a, b);
}

void	move_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tar;

	tar = find_cheapest(*b);
	move_two_nodes(a, b, tar);
	while (*a != tar->target_node || *b != tar)
	{
		if (*a != tar->target_node)
		{
			if (tar->target_node->above_median)
				ra(a);
			else
				rra(a);
		}
		if (*b != tar)
		{
			if (tar->above_median)
				rb(b);
			else
				rrb(b);
		}
	}
}
