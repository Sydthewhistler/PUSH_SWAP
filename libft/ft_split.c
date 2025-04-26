/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:22:29 by scavalli          #+#    #+#             */
/*   Updated: 2025/04/02 21:53:27 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup2(const char *s1, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	while (i < end - start)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c || i == 0))
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_free_all(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	if (!tab[j])
	{
		while (i <= j)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (-1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 1;
	tab = malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strdup2(s, start, i);
		if (ft_free_all(tab, j) == -1)
			return (NULL);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
