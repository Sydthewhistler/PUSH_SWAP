/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:00:15 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/30 18:28:53 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BELOW 1
# define ABOVE 0
# define A_TO_B 0
# define B_TO_A 1
# define STACK_A 0
# define STACK_B 1
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	long int		index;
	bool			position_from_median;
	int				push_cost;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

int					check_av(char **av);
int					ft_strcmp(const char *s1, const char *s2);
void				node_initiation_a(t_stack *stack_from, t_stack *stack_to);
void				node_initiation_b(t_stack *stack_a, t_stack *stack_b);
void				define_index(t_stack *lst);

int	algorithm(char **av);
void				initialise_stack_a(char **av, t_stack **stack_a);
void				ft_lst_add_new_last(t_stack **stack, int content);
unsigned int		stack_size(t_stack *stack_a);
void				sort_three(t_stack **lst);
void				sort_turk(t_stack **stack_a, t_stack **stack_b);
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void				move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void				ft_lstclear_stack(t_stack **lst);
bool				check_if_sorted(t_stack *lst);

t_stack				*find_max(t_stack *lst);
t_stack				*find_min(t_stack *stack_a);
t_stack				*find_last(t_stack *stack);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						bool which_stack);
void				put_min_top(t_stack **top_node);

void				rr(t_stack **stack_from, t_stack **stack_to);
void				rotate(t_stack **stack);
void				ra(t_stack **stack);
void				rb(t_stack **stack);

void				push(t_stack **src, t_stack **dst);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				rrr(t_stack **stack_from, t_stack **stack_to);
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);

void				sa(t_stack **stack);

//debug functions

void display_stack(t_stack *stack);
void display_target_stack(t_stack *stack);
void	check_sorted_stack(t_stack *stack);


#endif