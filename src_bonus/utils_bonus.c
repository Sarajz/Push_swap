/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:46:14 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 17:36:49 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (n == 0)
		return (0);
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_argv( char *argv)
{
	if (!(ft_strncmp(argv, "ra\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "rb\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "rr\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "sa\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "sb\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "ss\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "pa\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "pb\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "rra\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "rrb\n", 3)))
		return (0);
	if (!(ft_strncmp(argv, "rrr\n", 3)))
		return (0);
	return (1);
}

void	do_rotate(t_stack_node **a, t_stack_node **b, char *argv)
{
	if (!(ft_strncmp(argv, "ra\n", 3)))
		node_rotate(a);
	if (!(ft_strncmp(argv, "rb\n", 3)))
		node_rotate(b);
	if (!(ft_strncmp(argv, "rr\n", 3)))
	{
		node_rotate(a);
		node_rotate(b);
	}
}

void	make_commands(t_stack_node **a, t_stack_node **b, char *argv)
{
	do_rotate (a, b, argv);
	if (!(ft_strncmp(argv, "sa\n", 3)))
		node_swap(a);
	if (!(ft_strncmp(argv, "sb\n", 3)))
		node_swap(b);
	if (!(ft_strncmp(argv, "ss\n", 3)))
	{
		node_swap(a);
		node_swap(b);
	}
	if (!(ft_strncmp(argv, "pa\n", 3)))
		node_push(a, b);
	if (!(ft_strncmp(argv, "pb\n", 3)))
		node_push(a, b);
	if (!(ft_strncmp(argv, "rra\n", 3)))
		node_reverse_rotate(a);
	if (!(ft_strncmp(argv, "rrb\n", 3)))
		node_reverse_rotate(b);
	if (!(ft_strncmp(argv, "rrr\n", 3)))
	{
		node_reverse_rotate(a);
		node_reverse_rotate(b);
	}
}

void	is_ok_ko(t_stack_node **a, t_stack_node	**b)
{
	if (stack_is_sorted(*a) && (stack_len(*b) == 0))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	if (*a)
		free (*a);
	if (*b)
		free (*b);
}
