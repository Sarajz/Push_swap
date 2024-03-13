/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:44:44 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 18:04:13 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	node_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	*stack = temp->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack_node **a)
{
	node_rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	node_rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	node_rotate(a);
	node_rotate(b);
	write (1, "rr\n", 3);
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
// 	print(nodeA);
// 	printf("\n");	
// 	ra_rotate(&nodeA);	
// 	print(nodeA);
// 	printf("\n");
// 	return (0);
// }
