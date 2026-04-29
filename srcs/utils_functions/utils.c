/* utils.c - allocation error handler and string equality */

#include "../../inc/header.h"

/*
 * If new_node is NULL (malloc failed), free the list built so far
 * and return -1 to signal the caller to abort.
 */
int	list_free_on_error(t_stack *list, t_stack *new_node)
{
	t_stack	*tmp;

	if (!new_node)
	{
		while (list)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
		return (-1);
	}
	return (0);
}

/* Returns true if s1 and s2 are identical, false otherwise. */
bool	str_equal(const char *s1, const char *s2)
{
	for (size_t i = 0; ; i++)
	{
		if (s1[i] != s2[i])
			return (false);
		if (!s1[i])
			return (true);
	}
}
