/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:11:19 by sarajime          #+#    #+#             */
/*   Updated: 2024/02/29 19:39:10 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalnum(char **argv, t_stack_node **a, t_stack_node **b)
{
	int	i;
	int	j;

	j = 0;
	while (argv[j])
	{
		i = 0;
		if (!(argv[j][i] >= '0' && argv[j][i] <= '9')
		&& (argv[j][i] != '+' && argv[j][i] != '-'))
			ab_error(a, b);
		if ((argv[j][i] == '+' || argv[j][i] == '-')
		&& !(argv[j][i + 1] >= '0' && argv[j][i + 1] <= '9'))
			ab_error(a, b);
		while (argv[j][++i])
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				ab_error(a, b);
		j++;
	}
	return (1);
}
