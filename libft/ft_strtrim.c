/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:51:56 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/03 22:48:35 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	i;
	size_t	j;

	end = ft_strlen(s1) - 1;
	i = 0;
	j = 0;
	while (is_set(s1[end], set))
		end--;
	while (is_set(s1[i], set))
		i++;
	str = malloc(end - i + 2);
	if (!str)
		return (NULL);
	while (i <= end)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
