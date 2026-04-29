/* stack_functions.c - stack allocation, deallocation and size */

#include "../../inc/header.h"

void	stack_push_back(t_stack **stack, int content)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->content = content;
	node->next = NULL;
	node->cheapest = false;
	if (!*stack)
	{
		node->previous = NULL;
		*stack = node;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->previous = last;
	}
}

void	stack_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

unsigned int	stack_size(t_stack *stack)
{
	unsigned int	size;

	for (size = 0; stack; stack = stack->next)
		size++;
	return (size);
}
