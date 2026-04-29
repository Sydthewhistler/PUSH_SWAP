/* find_quartile.c - quartile computation and pre-sort push to B */

#include "../../inc/header.h"

static void	list_append_node(t_stack **list, t_stack *node)
{
	t_stack	*tail;

	if (!*list)
	{
		*list = node;
		return ;
	}
	for (tail = *list; tail->next; tail = tail->next)
		;
	tail->next = node;
}

static t_stack	*create_filtered_list(t_stack *lst, int median, int is_upper)
{
	t_stack	*filtered;
	t_stack	*node;

	filtered = NULL;
	for (; lst; lst = lst->next)
	{
		if ((is_upper && lst->content > median)
			|| (!is_upper && lst->content < median))
		{
			node = malloc(sizeof(t_stack));
			if (list_free_on_error(filtered, node) == -1)
				return (NULL);
			node->content = lst->content;
			node->next = NULL;
			list_append_node(&filtered, node);
		}
	}
	return (filtered);
}

int	find_quartile(t_stack *lst, int median, int is_upper)
{
	t_stack	*filtered;
	t_stack	*tmp;
	int		quartile;

	filtered = create_filtered_list(lst, median, is_upper);
	if (!filtered)
		return (0);
	quartile = find_median(filtered);
	while (filtered)
	{
		tmp = filtered;
		filtered = filtered->next;
		free(tmp);
	}
	return (quartile);
}

static void	push_lower_quartiles(t_stack **a, t_stack **b,
				int q1, int median)
{
	while (stack_size(*a) > 3 && has_value_below(*a, q1))
	{
		if ((*a)->content < q1)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3 && has_value_below(*a, median))
	{
		if ((*a)->content >= q1 && (*a)->content < median)
			pb(a, b);
		else
			ra(a);
	}
}

void	push_by_quartiles(t_stack **a, t_stack **b)
{
	int	q1;
	int	median;
	int	q3;

	if (stack_size(*a) <= 3)
		return ;
	median = find_median(*a);
	q1 = find_quartile(*a, median, LOWER_QUARTILE);
	q3 = find_quartile(*a, median, UPPER_QUARTILE);
	push_lower_quartiles(a, b, q1, median);
	while (stack_size(*a) > 3 && has_value_below(*a, q3))
	{
		if ((*a)->content >= median && (*a)->content < q3)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
}
