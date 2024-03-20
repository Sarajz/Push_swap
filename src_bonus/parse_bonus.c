/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:24:15 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/19 19:17:32 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atol(const char *str)
{
	long	i;
	long	j;
	long	result;

	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * j);
}

void	atol_to_stack(t_stack_node **a, char **argv)
{
	long	i;
	long	digit;

	i = 0;
	while (argv[i])
	{
		digit = ft_atol(argv[i]);
		if (digit > INT_MAX || digit < INT_MIN)
			a_error(a);
		ft_lstadd_back(a, ft_lstnew((int)digit));
		i++;
	}
	ft_free_pointer(argv);
}

int	no_duplicate(t_stack_node *a)
{
	t_stack_node	*temp;

	if (!a)
		return (0);
	while (a->next)
	{
		temp = a->next;
		while (temp)
		{
			if (a->digit == temp->digit)
				return (0);
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

char	**join_and_split(char **argv)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = malloc(1);
	while (argv[++i])
	{
		temp2 = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(temp2, argv[i]);
		free(temp2);
	}
	argv = ft_split(temp, ' ');
	free(temp);
	return (argv);
}

t_stack_node	*parse(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (NULL);
	else if (argc == 2 && !argv[1][0])
		ab_error(&a, &b);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc >= 3)
		argv = join_and_split (argv);
	ft_isalnum(argv, &a, &b);
	atol_to_stack(&a, argv);
	if (no_duplicate(a) == 0)
		a_error(&a);
	return (a);
}
