/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:41:26 by sarajime          #+#    #+#             */
/*   Updated: 2024/03/13 16:59:09 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack_node
{
	int					digit;
	int					index;
	int					push_cost;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node	*ft_lstnew(int digit);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
void			print(t_stack_node *a);
void			ab_error(t_stack_node **a, t_stack_node **b);
void			a_error(t_stack_node **a);
int				ft_isalnum(char **argv, t_stack_node **a, t_stack_node **b);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			**join_and_split(char **argv);
long			ft_atol(const char *str);
void			atol_to_stack(t_stack_node **a, char **argv);
int				no_duplicate(t_stack_node *a);
t_stack_node	*parse(int argc, char **argv);
void			put_index(t_stack_node *stack);
void			ft_free_pointer(char **str);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
int				stack_is_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
int				num_media(t_stack_node *a);
int				stack_len(t_stack_node *stack);
t_stack_node	*free_stack(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);
void			init_node(t_stack_node **a, t_stack_node **b);
void			move_node(t_stack_node **a, t_stack_node **b);
t_stack_node	*cheapest_a(t_stack_node *stack);
void			cost_analysis(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);

void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			node_push(t_stack_node **src, t_stack_node **dst);
void			node_reverse_rotate(t_stack_node **stack);
void			node_rotate(t_stack_node **stack);
void			node_swap(t_stack_node **stack);

char			*get_next_strjoin(char const *s1,
					char const *s2, int num_bytes);
char			*ft_strchr(char *s, int c);
char			*ft_read_and_stash(int fd, char	*stash);
char			*ft_line(char *stash);
char			*ft_clean_stash(char	*stash);
char			*get_next_line(int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				check_argv( char *argv);
void			do_rotate(t_stack_node **a, t_stack_node **b, char *argv);
void			make_commands(t_stack_node **a, t_stack_node **b, char *argv);
void			is_ok_ko(t_stack_node **a, t_stack_node	**b);

#endif