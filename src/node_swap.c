/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:49:33 by sarajime          #+#    #+#             */
/*   Updated: 2024/02/22 17:51:08 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_swap(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack_node **a)
{
	node_swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	node_swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	node_swap(a);
	node_swap(b);
	write (1, "ss\n", 3);
}

// void	print(t_stack_node *a)
// {
// 	while (a)
// 	{
// 		printf("%d", a->digit);
// 		a = a->next;
// 	}
// }

// int	main()
// {
// 	t_stack_node *nodea = malloc(sizeof(t_stack_node));
// 	t_stack_node *nodeB = malloc(sizeof(t_stack_node));
// 	t_stack_node *nodeC = malloc(sizeof(t_stack_node));

// 	nodea->digit = 1;
// 	nodeB->digit = 2;
// 	nodeC->digit = 3;
// 	nodea->next = nodeB;
// 	nodeB->next = nodeC;
// 	nodeC->next = NULL;
// 	print (nodea);
// 	printf ("\n");
// 	sb_swap(&nodea);
// 	print (nodea);
// 	printf ("\n");
// 	return (0);
// }
