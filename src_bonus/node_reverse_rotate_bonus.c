/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:43:26 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/21 18:24:15 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	node_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	temp = *stack;
	last = ft_lstlast(*stack);
	if (*stack == NULL || ((*stack)->next) == NULL)
		return ;
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	node_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	node_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	node_reverse_rotate(a);
	node_reverse_rotate(b);
	write(1, "rrr\n", 4);
}

// void	print(t_stack_node *a)
// 	{
// 		while (a)
// 		{
// 			printf("%d", a->digit);
// 			a = a->next;
// 		}
// 	}

// int	main(void)
// {
// 	t_stack_node *nodeA = malloc(sizeof(t_stack_node));
// 	t_stack_node *nodeB = malloc(sizeof(t_stack_node));
// 	t_stack_node *nodeC = malloc(sizeof(t_stack_node));
// 	nodeA->digit = 1;
// 	nodeB->digit = 2;
// 	nodeC->digit = 3;

// 	nodeA->next = nodeB;
// 	nodeB->next = nodeC;
// 	nodeC->next = NULL;
// 	print(nodeA);
// 	printf("\n");
// 	rrr_reverse_rotate(&nodeA, &nodeA);
// 	print(nodeA);
// 	printf("\n");
// 	return (0);
// }
