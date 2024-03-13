/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:33:31 by sarajime          #+#    #+#             */
/*   Updated: 2024/02/28 11:54:26 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *a, char *str)
{
	printf("STACK %s:\n", str);
	while (a)
	{
		printf("VALOR DEL NODO %d ", a->digit);
		printf("VALOR INDEX %d ", a->index);
		printf("CHEAPEST %d ", a->cheapest);
		printf("COST %d\n", a->push_cost);
		a = a->next;
	}
}
void	print_stack_tar(t_stack_node *a, char *str)
{
	printf("STACK %s:\n", str);
	while (a)
	{
		printf("VALOR DEL NODO %d ", a->digit);
		printf("VALOR INDEX %d ", a->index);
		printf("CHEAPEST %d ", a->cheapest);
		printf("TAR %d ", a->target_node->digit);
		printf("COST %d\n", a->push_cost);
		a = a->next;
	}
}