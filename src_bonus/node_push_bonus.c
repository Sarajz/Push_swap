/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:25:01 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 18:04:08 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	node_push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*temp;

	if (!dst || !src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	node_push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	node_push(a, b);
	write (1, "pb\n", 3);
}

// void	print(t_stack_node *a)
// 	{
// 		while (a)
// 		{
// 			printf("%d", a->digit);
// 			a = a->next;
// 		}
// 	}

// int	main()
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
// 	t_stack_node *node1 = malloc(sizeof(t_stack_node));
// 	t_stack_node *node2 = malloc(sizeof(t_stack_node));
// 	t_stack_node *node3 = malloc(sizeof(t_stack_node));

// 	node1->digit = 4;
// 	node2->digit = 5;
// 	node3->digit = 6;

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;	
// 	print(nodeA);
// 	printf("\n");	
// 	pa_push(&nodeA, &node1);	
// 	print(nodeA);
// 	printf("\n");
// 	print(node1);
// 	printf("\n");
// 	return (0);
// }
