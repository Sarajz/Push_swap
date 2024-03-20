/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:17 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/20 18:20:52 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	commands(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_line(line))
		{
			free(line);
			ab_error(a, b);
		}
		make_commands(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	is_ok_ko(a, b);
}

void leaks()
{
	system("leaks checker");
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	a = parse(argc, argv);
	commands(&a, &b);
	return (0);
}

// "sa\nsb\nss\npa\npb\npa\npb\nsb\npa\nra\nrb\nrr\nrra\nrrb\nrrr"