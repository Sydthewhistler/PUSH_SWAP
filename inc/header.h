#ifndef HEADER_H
#define HEADER_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../libft/libft.h"

/* ── Which stack (used by bring_node_to_top) ─────────────────────── */
#define STACK_A         false
#define STACK_B         true

/* ── Quartile selectors ───────────────────────────────────────────── */
#define UPPER_QUARTILE  1
#define LOWER_QUARTILE  0

/*
 * Doubly linked stack node.
 * position_from_median: true  → node is in the top half (index < median)
 *                        false → node is in the bottom half
 */
typedef struct s_stack
{
	int				content;
	long			index;
	bool			position_from_median;
	int				push_cost;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

/* ── Input validation ────────────────────────────────────────────── */
int				validate_args(char **av, int ac);

/* ── Stack management ────────────────────────────────────────────── */
void			stack_a_init(char **av, t_stack **stack_a);
void			stack_push_back(t_stack **stack, int content);
void			stack_free(t_stack **lst);
unsigned int	stack_size(t_stack *stack);
t_stack			*find_last(t_stack *stack);
t_stack			*find_max(t_stack *stack);
t_stack			*find_min(t_stack *stack);

/* ── Index / target helpers ──────────────────────────────────────── */
void			stack_index_nodes(t_stack *lst);
void			prepare_b_nodes(t_stack *stack_a, t_stack *stack_b);
int				list_free_on_error(t_stack *list, t_stack *new_node);
bool			str_equal(const char *s1, const char *s2);

/* ── Rotation helpers ────────────────────────────────────────────── */
void			bring_node_to_top(t_stack **stack, t_stack *node,
					bool which_stack);
void			rotate_min_to_top(t_stack **stack);

/* ── Stack operations ────────────────────────────────────────────── */
void			push(t_stack **src, t_stack **dst);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);

void			rotate(t_stack **stack);
void			ra(t_stack **stack);
void			rb(t_stack **stack);
void			rr(t_stack **a, t_stack **b);

void			reverse_rotate(t_stack **stack);
void			rra(t_stack **stack);
void			rrb(t_stack **stack);
void			rrr(t_stack **a, t_stack **b);

void			swap_top(t_stack **stack);
void			sa(t_stack **stack);

/* ── Median / quartile ───────────────────────────────────────────── */
int				find_median(t_stack *stack);
bool			has_value_below(t_stack *stack, int threshold);
int				find_quartile(t_stack *lst, int median, int is_upper);
void			push_by_quartiles(t_stack **a, t_stack **b);

/* ── Sorting ─────────────────────────────────────────────────────── */
bool			is_sorted(t_stack *lst);
int				algorithm(char **av, int ac);
void			sort_three(t_stack **stack);
void			sort_turk(t_stack **stack_a, t_stack **stack_b);
void			move_b_to_a(t_stack **a, t_stack **b);

#endif /* HEADER_H */
